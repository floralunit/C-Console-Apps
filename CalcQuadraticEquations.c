#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcD (int _a, int _b, int _c) {
    double _D = _b*_b - 4.0f*_a*_c;
    return _D;
}

double calcX (int _a, int _b, int _c, double _D, int sign) {
    double _x = (-_b + sign * sqrt(_D)) / (2.0f * _a);
    return _x;
}

int main() {
    int exit = 1, s, a, b, c;
    printf("=====Решение квадратных уравнений вида ax^2+bx+c=0=====\n");
	
    while (exit != 0) {
        printf("1 способ. Разложение левой части уравнения на множители\n");
        printf("2 способ. Метод выделения полного квадрата\n");
        printf("3 способ. Решение квадратных уравнений по формуле\n");
        printf("4 способ. Решение уравнений с использованием теоремы Виета\n");
        printf("5 способ. Решение уравнений способом «переброски»\n");
        printf("6 способ. Свойства коэффициентов квадратного уравнения\n");
        printf("7 способ. Графическое решение квадратного уравнения\n");
        printf("Выберете способ решения => ");
        scanf("%d", &s);
		
        if (!(s >= 1 && s <= 7)) {
            printf("Такого способа не существует!\n");
            exit = 0;
        }
        if (exit != 0) {
            printf("Введите a => ");
            scanf("%d", &a);
            printf("Введите b => ");
            scanf("%d", &b);
            printf("Введите c => ");
            scanf("%d", &c);
        }
		
        switch (s) {
			
            case 1: {
                printf("===1 способ. Разложение левой части уравнения на множители\n");
                double D = calcD(a, b, c);
                if (D < 0.0f) {
                    printf("Уравнение не имеет корней!");
                }
                else if (D == 0.0f) {
                    double x = -b / (2.0f * a);
                    printf("Получаем следующее выражение: %d(x - %*.*lf) * (x - %*.*lf)\n", a, 1, 2, x, 1, 2, x);
                    printf("Уравнение имеет единственный корень x => %*.*lf\n", 1, 2, x);
                }
                else {
                    double x1 = calcX (a, b, c, D, 1);
                    double x2 = calcX (a, b, c, D, -1);
                    printf("Получаем следующее выражение: %d(x - %*.*lf) * (x - %*.*lf)\n", a, 1, 2, x1, 1, 2, x2);
                    printf("x1 => %*.*lf\n", 1, 2, x1);
                    printf("x2 => %*.*lf\n", 1, 2, x2);
                }
            } break;
			
            case 2: {
                printf("===2 способ. Метод выделения полного квадрата\n");
                double m = -(double)b / (2.0f * (double)a);
                double n = -((double)b * (double)b - 4.0f * a * c) / (4.0f * (double)a);
                printf("Получаем следующее выражение: %d(x - %*.*lf)^2 + %*.*lf\n", a, 1, 2, m, 1, 2, n);
                double x1 = sqrt(-n / (double)a) + m;
                double x2 = -sqrt(-n / (double)a) + m;
                printf("x1 => %*.*lf\n", 1, 2, x1);
                printf("x2 => %*.*lf\n", 1, 2, x2);
            } break;
			
            case 3: {
                printf("===3 способ. Решение квадратных уравнений по формуле\n");
                double D = calcD(a, b, c);
                printf("Дискриминант => %lf\n", D);
                if (D < 0.0f) {
                    printf("Уравнение не имеет корней!");
                }
                else if (D == 0.0f) {
                    double x = -b / (2.0f * a);
                    printf("Уравнение имеет единственный корень x => %*.*lf\n", 1, 2, x);
                }
                else {
                    double x1 = calcX (a, b, c, D, 1);
                    double x2 = calcX (a, b, c, D, -1);
                    printf("x1 => %*.*lf\n", 1, 2, x1);
                    printf("x2 => %*.*lf\n", 1, 2, x2);
                }
            } break;
			
            case 4: {
                printf("===4 способ. Решение уравнений с использованием теоремы Виета\n");
                double x1,x2;
                int fl=0, hasX = 0;
                for(x1=-20;x1<=20;x1+=0.01) {
                    for(x2=-20; x2<=20;x2+=0.01)
                    if(fabs(x1+x2+(double)b/(double)a)<=0.001 && fabs(x1*x2-(double)c/(double)a)<=0.001)
                    {
                        printf("x1 => %*.*lf\n", 1, 2, x1);
                        printf("x2 => %*.*lf\n", 1, 2, x2);
                        hasX = 1;
                        fl=1;
                    }
                    if(fl) break;
                } 
                if (hasX == 0)
                    printf("Уравнение не имеет корней!");
            } break;
			
            case 5: {
                printf("===5 способ. Решение уравнений способом «переброски»\n");
                if (a == 0) {
                    printf("Для a = 0 данный способ применять нельзя!\n");
                    break;
                }
                int _a = 1;
                int _c = a * c;
                double D = calcD (_a, b, _c);
                double y1 = calcX (_a, b, _c, D, 1);
                double y2 = calcX (_a, b, _c, D, -1);
                printf("y1 => %lf\n", y1);
                printf("y2 => %lf\n", y2);
                double x1 = y1 / a;
                double x2 = y2 / a;
                printf("x1 => %*.*lf\n", 1, 2, x1);
                printf("x2 => %*.*lf\n", 1, 2, x2);
            } break;
			
            case 6: {
                printf("===6 способ. Свойства коэффициентов квадратного уравнения\n");
                if (a == 0) {
                    printf("Для a = 0 данный способ применять нельзя!\n");
                    break;
                }
                if ((a + b + c) == 0) {
                    printf("x1 => 1\n");
                    printf("x2 => %*.*lf\n", 1, 2, (double)c / (double)a);
                }
                else
                    printf("Сумма коэффициентов a + b + c не равна 0!\n");
            } break;
			
            case 7: {
                printf("===7 способ. Графическое решение квадратного уравнения\n");
                printf("Уравнение параболы => y=%dx^2\n", a);
                printf("Уравнение прямой => y=-%dx-%d\n", b, c);
                int hasX = 0;
                for(int x=-30; x<=30;x+=1) {
                    int y1 = a * x * x;
                    int y2 = -b * x - c;
                    if(y1 == y2) {
                        printf("Парабола и прямая пересекаются в точке p(%d;%d) => \n", x, y1);
                        printf("x => %d\n", x);
                        hasX = 1;
                    }
                }
                if (hasX == 0)
                    printf("Уравнение не имеет корней!");
            } break;
			
            default : break;
        }
        printf("\nВыйти? (1-Нет 0-Да) => ");
        scanf("%d", &exit);
    }
}