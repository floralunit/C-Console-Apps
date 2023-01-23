#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include "/Users/floralunit/Documents/GitHub/c-labs/help/one_dim_arr_func.h"
#include "dynamic_multi_arr.h"

int inputArrCol()
{
  int j;
  printf("\nВведите количество столбцов => ");
  scanf("%d", &j);
  return j;
}

int inputArrRows()
{
  int i;
  printf("Введите количество строк => ");
  scanf("%d", &i);
  return i;
}

int **createDimArray(int r, int c)
{
  int **table;
  table = malloc(c * sizeof(*table));
  for (int i = 0; i < c; i++)
  {
    table[i] = malloc(r * sizeof(table[0]));
  }
  return table;
}

void print_array(int **arr, int m, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      printf("%5d ", arr[i][j]);
    }
    printf("\n");
  }
}

int **initArrCode(int **arr, int m, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      arr[i][j] = i - j;
    }
  }
  return arr;
}

int **initArrRandom(int **arr, int m, int n)
{
  srand(time(NULL));
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      arr[i][j] = 1 + rand() % 9;
    }
  }
  return arr;
}

int **initArrConsole(int **arr, int m, int n)
{
  printf("Начинаем заполнять массив: \n");
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      printf("arr[%d][%d] = ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
  return arr;
}

int **initArrFile(FILE *fp, int **arr, int m, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      fscanf(fp, "%d", &arr[i][j]);
    }
  }
  return arr;
}

int **initArray(int **arr, int m, int n)
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
    arr = initArrCode(arr, m, n);
    printf("Исходный массив:\n");
    print_array(arr, m, n);
  }
  break;

  case 2:
  {
    arr = initArrRandom(arr, m, n);
    printf("Исходный массив:\n");
    print_array(arr, m, n);
  }
  break;

  case 3:
  {
    arr = initArrConsole(arr, m, n);
    printf("Исходный массив:\n");
    print_array(arr, m, n);
  }
  break;

  case 4:
  {
    char fname[24];
    printf("Введите название файла, в котором содержатся числа => ");
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
      arr = initArrFile(myFile, arr, m, n);
      printf("Исходный массив:\n");
      print_array(arr, m, n);
      fclose(myFile);
    }
  }
  break;
  default:
    break;
  }
  return arr;
}

void write_array_to_file(FILE *fp, int **arr, int m, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      fprintf(fp, "%5d ", arr[i][j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

void read_file(FILE *fp)
{
  char c;
  do
  {
    c = fgetc(fp);
    printf("%c", c);
  } while (c != EOF);
  fclose(fp);
}

int print_array_ways(int **arr, int m, int n)
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
    print_array(arr, m, n);
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
      write_array_to_file(myFile, arr, m, n);
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