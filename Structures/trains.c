#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "structFileLib.c"

void InputTrain(struct Train *trains, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Введите номер поезда: ");
        scanf("%d", &trains[i].Number);

        printf("Введите станцию назначения поезда: ");
        scanf("%s", trains[i].Title);

        printf("Введите время в пути: ");
        scanf("%d", &trains[i].Time);

        printf("Введите цену билета: ");
        scanf("%lf", &trains[i].Price);

        printf("\n");
    }
}

void PrintTrain(struct Train trains[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Номер поезда: %d\n", trains[i].Number);
        printf("Станция назначения поезда: %s\n", trains[i].Title);
        printf("Время в пути: %d\n", trains[i].Time);
        printf("Цена билета: %lf\n", trains[i].Price);
        printf("\n");
    }
}

int main()
{
    int n, k, init;
    double m;
    printf("\n====Способ ввода структуры====\n");
    printf("Способ 1. Ввод через консоль\n");
    printf("Способ 2. Чтение из файла\n");
    printf("\nВыберете способ инициализации структуры => ");
    scanf("%d", &init);

    if (!(init >= 1 && init <= 2))
    {
        printf("Такого способа не существует!\n");
        return (0);
    }

    switch (init)
    {
    case 1:
    {
        printf("\nВведите количество поездов => ");
        scanf("%d", &n);
        struct Train trains[n];

        InputTrain(trains, sizeof(trains) / sizeof(*trains));

        int save = 0;
        printf("Сохранить структуры в файле? 1-Да 0-Нет: ");
        scanf("%d", &save);
        if (save == 1)
        {
            char *filename = "trains.txt";
            saveFile(filename, trains, n);
        }

        printf("\n\n==Cведения о поездах, находящихся в пути > k часов, и цена билета которых < m рублей==\n\n");

        printf("Введите количество часов k => ");
        scanf("%d", &k);

        printf("Введите цену билета m => ");
        scanf("%lf", &m);
        printf ("\n");
        struct Train trainsCopy[n];
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (trains[i].Time > k && trains[i].Price < m)
            {
                printf("Номер поезда: %d\n", trains[i].Number);
                printf("Станция назначения поезда: %s\n", trains[i].Title);
                printf("Время в пути: %d\n", trains[i].Time);
                printf("Цена билета: %lf\n", trains[i].Price);

                trainsCopy[i].Number = trains[i].Number;
                strcpy(trainsCopy[i].Title, trains[i].Title);
                trainsCopy[i].Time = trains[i].Time;
                trainsCopy[i].Price = trains[i].Price;
                c++;
            }
        }
        printf("Сохранить вывод в файле? 1-Да 0-Нет: ");
        scanf("%d", &save);
        if (save == 1)
        {
            char *filename = "trainsCopy.txt";
            saveFile(filename, trainsCopy, c);
        }
    }
    break;
    case 2:
    {
        char *filename = "trains.txt";
        struct Train *trains = loadFile(filename);

        printf("==Cведения о поездах, находящихся в пути > k часов, и цена билета которых < m рублей==\n\n");

        printf("Введите количество часов k => ");
        scanf("%d", &k);

        printf("Введите цену билета m => ");
        scanf("%lf", &m);

        printf ("\n");
        struct Train trainsCopy[n];
        int c = 0;

        for (int i = 0; i < 10; i++)
        {
            if (trains[i].Time > k && trains[i].Price < m)
            {
                printf("Номер поезда: %d\n", trains[i].Number);
                printf("Станция назначения поезда: %s\n", trains[i].Title);
                printf("Время в пути: %d\n", trains[i].Time);
                printf("Цена билета: %lf\n", trains[i].Price);
                
                trainsCopy[i].Number = trains[i].Number;
                strcpy(trainsCopy[i].Title, trains[i].Title);
                trainsCopy[i].Time = trains[i].Time;
                trainsCopy[i].Price = trains[i].Price;
                c++;
            }
        }
        free(trains);
        int save = 0;
        printf("Сохранить вывод в файле? 1-Да 0-Нет: ");
        scanf("%d", &save);
        if (save == 1)
        {
            char *filename = "trainsCopy.txt";
            saveFile(filename, trainsCopy, c);
        }
    }
    break;
    default:
        break;
    }

    return 0;
}
