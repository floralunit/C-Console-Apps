#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void read_file(FILE *fp);
void create_file();

int main(void)
{
    char *locale = setlocale(LC_ALL, "");
    create_file();

    char fnameOpen[24], fnameWrite[24];
    printf("Введите название файла, в котором содержатся числа => ");
    scanf("%23s", fnameOpen);

    printf("Введите название файла, в который нужно записать среднее арифметическое => ");
    scanf("%23s", fnameWrite);
    FILE *myFileOpen, *myFileWrite;

    myFileOpen = fopen(fnameOpen, "r");
    myFileWrite = fopen(fnameWrite, "w");
    if (myFileOpen == NULL || myFileWrite == NULL)
    {
        printf("Ошибка при открытии файла!\n");
        return (0);
    }
    else
    {
        // Переменная, в которую поочередно будут помещаться считываемые строки
        char str[80];
        //Указатель, в который будет помещен адрес массива, в который считана
        // строка, или NULL если достигнут коней файла или произошла ошибка
        char *estr;

        printf("\nЧитаем файл с числами!\n");
        while (1)
        {
            // Чтение одной строки  из файла
            estr = fgets (str,sizeof(str),myFileOpen);

            //Проверка на конец файла или ошибку чтения
            if (estr == NULL)
            {
                // Проверяем, что именно произошло: кончился файл
                // или это ошибка чтения
                if ( feof (myFileOpen) != 0)
                {
                    //Если файл закончился, выводим сообщение о завершении
                    //чтения и выходим из бесконечного цикла
                    printf ("\nЧтение файла закончено\n");
                    break;
                }
                else
                {
                    //Если при чтении произошла ошибка, выводим сообщение
                    //об ошибке и выходим из бесконечного цикла
                    printf ("\nОшибка чтения из файла\n");
                    break;
                }
            }
            //Если файл не закончился, и не было ошибки чтения
            //выводим считанную строку  на экран

            char *endp = str;
            int i, j=0;
            int len=strlen(str);
            int *array = malloc(len*sizeof(int));
            printf("    %s", str);
            for (i=0;i<len;i++)
                if(str[i]!=' ') {
                    array[ j++ ]=strtol(str, &endp, 10);
                    strcpy(str, endp);
                }
            int sum = 0, count = 0;
            for ( i = 0; i < j; i ++ ){
                if (array[i] != 0)
                    count++;
                //printf( "[%i]: %d\n", i, array[i] );
            }
            for ( i = 0; i < count; i ++ ){
                if (array[i] != 0)
                    sum += array[i];
            }

            double sred = (double)sum / count;
            fprintf(myFileWrite, "%lf", sred);
            fprintf(myFileWrite, "\n");
        }
        fclose(myFileOpen);
        fclose(myFileWrite);

        printf("\nЧитаем файл со средними значениями!\n");
        FILE *myFile;
        myFile = fopen(fnameWrite, "r");
        if (myFileWrite == NULL)
        {
            printf("Ошибка при открытии файла!\n");
            return (0);
        }
        read_file(myFile);
    }
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

void create_file()
{
    int yes = 0;
    printf("Создать файл и заполнить его числами? Да-1 Нет-0 => ");
    scanf("%d", &yes);
    if (yes == 1){
        char fname[24];
        printf("Введите название файла => ");
        scanf("%23s", fname);
        FILE *fp;
        fp = fopen(fname, "w");
        if (fp == NULL)
        {
            printf("Ошибка при создании файла!\n");
        }
        else{
            int rows = 1 + rand()%20;
            for (int i = 0; i < rows; i++){
                int countNums = 1 + rand()%10;
                for (int j = 0; j < countNums; j++){
                    int num = 1 + rand()%15;
                    fprintf(fp, "%d", num);
                    fprintf(fp, " ");
                }
                fprintf(fp, "\n");
            }
            printf("Файл успешно создан!\n\n");
        }
        fclose(fp);
    }
}