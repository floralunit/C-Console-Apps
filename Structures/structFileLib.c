#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct Train
{
    int Number;
    char Title[50];
    int Time;
    double Price;
};

// запись в файл массива структур
int saveFile(char* filename, struct Train* st, int n)
{
    char* c;    // для записи отдельных символов
    // число записываемых байтов
    int size = n * sizeof(struct Train);
    FILE* fp = fopen(filename, "wb");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return 0;
    }
    // записываем количество структур
    c = (char*)&n;
    for (int i = 0; i < sizeof(n); i++)
    {
        putc(*c++, fp);
    }

    // посимвольно записываем в файл все структуры
    c = (char*)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 1;
}

// загрузка из файла массива структур
struct Train *loadFile(char* filename)
{
    char* c;    // для считывания отдельных символов
    int m = sizeof(int);    // сколько надо считать для получения размера массива
    int n;  // количество структур в массиве

    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return 0;
    }
    // выделяем память для хранения количества данных
    int* ptr_count = malloc(m);
    // считываем количество структур
    c = (char*)ptr_count;
    // пока не считаем m байт, сохраняем байт в выделенный блок для размера массива
    while (m > 0 && (*c = getc(fp)) != EOF)
    {
        c++;
        m--;
    }
    //получаем число элементов
    n = *ptr_count;
    free(ptr_count);    // освобождаем память
    // выделяем память для считанного массива структур
    struct Train* ptr = malloc(n * sizeof(struct Train));
    // устанавливаем указатель на блок памяти, выделенный для массива структур
    c = (char*)ptr;
    // считываем посимвольно из файла
    while ((*c = getc(fp)) != EOF)
    {
        c++;
    }
    // перебор загруженных элементов и вывод на консоль
    printf("\nНайдено %d поезда в файле\n\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Номер поезда: %d\n", ptr[i].Number);
        printf("Станция назначения поезда: %s\n", ptr[i].Title);
        printf("Время в пути: %d\n", ptr[i].Time);
        printf("Цена билета: %lf\n", ptr[i].Price);
        printf("\n");
    }

    /*for (int i = 0; i < n; i++)
    {
        printf("%-5d %5d %-10s %5d %5lf\n", i + 1, ptr[i].Number, ptr[i].Title, ptr[i].Time, ptr[i].Price);
        // или так
        //printf("%-5d %5d %-10s %5d %5lf\n", i + 1, (ptr + i)->Number, (ptr + i)->Title, (ptr + i)->Time, (ptr + i)->Price);
    }*/

    //free(ptr);
    fclose(fp);
    return ptr;
}