#include<stdio.h>
#include <locale.h>

int add(int x, int y)
{
    return x + y;
}
int subtract(int x, int y)
{
    return x - y;
}
int mult(int x, int y)
{
    return x * y;
}
int del(int x, int y)
{
    return x / y;
}

int main()
{
    char *locale = setlocale(LC_ALL, "");
    while (1 == 1) {
        int a, b;
        char n;
        printf("\nВведите два числа через пробел:");
        scanf("%d %d", &a, &b);
        printf("Введите знак операции:\n 1.Сложение +\n 2.Вычитание -\n 3.Умножение *\n");
        printf(" 4.Деление /\n 5.Выход 0\n => ");
        scanf(" %c", &n);

        int result;
        int (*operation)(int, int);

        if (n == '+') {
            operation = add;
            result = operation(a, b);
            printf("Сумма %d и %d равна %d ", a, b, result);
        } else if (n == '-') {
            operation = subtract;
            result = operation(a, b);
            printf("Разность %d и %d равна %d", a, b, result);
        } else if (n == '*') {
            operation = mult;
            result = operation(a, b);
            printf("Произведение %d и %d равно %d", a, b, result);
        } else if (n == '/') {
            if (b == 0) {
                printf("Ошибка! Делить на 0 нельзя.");
            } else {
                operation = del;
                result = operation(a, b);
                printf("Частное %d и %d равно %d", a, b, result);
            }
        } else if (n == '0')
            break;
        else
            printf("Неверно введен знак!");
    }
    return 0;
}