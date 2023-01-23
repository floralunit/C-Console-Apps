#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "/Users/floralunit/Documents/GitHub/c-labs/help/one_dim_arr_func.h"
#include "one_dim_arr.h"

int main()
{
    int exit = 0, task;
    printf("=====ПЗ-00: Работа с одномерными массивами=====\n");

    while (exit != 1)
    {
        printf("1. Задание 1\n");
        printf("2. Задание 2\n");
        printf("0. Выйти\n");
        printf("\nВыберете задание => ");
        scanf("%d", &task);

        if (!(task >= 1 && task <= 2))
        {
            printf("Такого задания не существует!\n");
            exit = 1;
        }
        if (task == 0)
        {
            exit = 1;
        }

        if (exit != 1)
        {
            int n = inputArrDim();
            int a[n];
            initArray(a, n);
            print_array_ways(a, n);
        }

        printf("\nВыйти? (1-Да 0-Нет) => ");
        scanf("%d", &exit);
    }
}