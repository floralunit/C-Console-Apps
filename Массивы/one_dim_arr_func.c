#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "one_dim_arr.h"

int inputArrDim()
{
    int n;
    printf("\nВведите размерность массива => ");
    scanf("%d", &n);
    return n;
}

void initArrCode(int *arr, int size)
{
    for (int i = 1; i <= size; i++)
    {
        arr[i] = i;
    }
}

void initArrRandom(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 1; i <= size; i++)
    {
        arr[i] = 1 + rand() % 9;
    }
}

void initArrConsole(int *arr, int size)
{
    printf("Начинаем заполнять массив: \n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]); // &a[i] - адрес i-го элемента массива
    }
}

void initArrFile(FILE *fp, int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d\n", &arr[i]);
    }
}

void print_array(int *arr, int size)
{
    int *p = arr;
    int *end = arr + size;
    char *pad = "{ ";

    while (p < end)
    {
        printf("%s%d", pad, *p++);
        pad = ", ";
    }
    printf(" }\n");
}

int initArray(int *arr, int size)
{
    int init;
    printf("\n====Способ инициализации массива====\n");
    printf("Способ 1. Прямая иницилизация в коде arr = {1, 2, 3, ... n}\n");
    printf("Способ 2. Иницилизация рандомными числами\n");
    printf("Способ 3. Ввод чисел массива через консоль\n");
    printf("Способ 4. Чтение чисел из файла\n");
    printf("\nВыберете способ иницилизации массива => ");
    scanf("%d", &init);

    if (!(init >= 1 && init <= 4))
    {
        printf("Такого способа инициализации массива не существует!\n");
        return (0);
    }

    switch (init)
    {
    case 1:
    {
        initArrCode(arr, size);
        printf("\nИсходный массив:\n");
        print_array(arr, size);
    }
    break;

    case 2:
    {
        initArrRandom(arr, size);
        printf("\nИсходный массив:\n");
        print_array(arr, size);
    }
    break;

    case 3:
    {
        initArrConsole(arr, size);
        printf("\nИсходный массив:\n");
        print_array(arr, size);
    }
    break;

    case 4:
    {
        char fname[24];
        printf("\nВведите название файла, в котором содержатся числа => ");
        scanf("%23s", fname);
        FILE *myFile;
        myFile = fopen(fname, "r");
        if (myFile == NULL)
        {
            printf("Ошибка при открытии файла!\n");
            return (0);
        }
        else
        {
            initArrFile(myFile, arr, size);
            printf("\nИсходный массив:\n");
            print_array(arr, size);
            fclose(myFile);
        }
    }
    break;
    default:
        break;
    }
    return 1;
}

void write_array_to_file(FILE *fp, int *arr, int size) // Запись массива в файл
{
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%d", arr[i]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void read_file(FILE *fp) // Чтение файла
{
    char c;
    do
    {
        c = fgetc(fp);
        printf("%c", c);
    } while (c != EOF);
    fclose(fp);
}

int print_array_ways(int *arr, int size) // Чтение массива
{
    int print;
    printf("\n====Способ вывода массива====\n");
    printf("Способ 1. Вывод в консоль\n");
    printf("Способ 2. Запись массива в файл и чтение из файла\n");
    printf("\nВыберете способ вывода массива => ");
    scanf("%d", &print);

    if (!(print >= 1 && print <= 2))
    {
        printf("Такого способа вывода массива не существует!\n");
        return (0);
    }

    switch (print)
    {

    case 1:
    {
        print_array(arr, size);
    }
    break;

    case 2:
    {
        char fname[24];
        printf("Введите название файла, в который нужно записать числа => ");
        scanf("%23s", fname);
        FILE *myFile;
        myFile = fopen(fname, "w");
        if (myFile == NULL)
        {
            printf("Ошибка при открытии файла!\n");
            return (0);
        }
        else
        {
            write_array_to_file(myFile, arr, size);
            FILE *file;
            file = fopen(fname, "r");
            read_file(file);
        }
    }
    break;
    default:
        break;
    }
    return 1;
}