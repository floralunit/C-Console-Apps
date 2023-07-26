#include <stdio.h>

typedef struct
{
	char Name[255]; /* Фамилия студента */
	int Group; /* Номер группы */
    int GradeArray[5];
	float Sred; /* Балл успеваемости */
} Student;

int main(int argc, char* argv[])
{
	/* Объявление и инициализация переменных и констант */
	const MAX_STUDENTS = 3; /* Определяет количество студентов */
	Student Stud1[MAX_STUDENTS];
	Student stTemp;
	int is = 0;
	/* Запрашиваем ввод данных с клавиатуры */
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		printf("Введите запись #%d:\n\tИмя: ", i+1);
		gets(Stud1[i].Name);
		printf("\tГруппа: ");
		scanf("%d", &Stud1[i].Group);
        int sum = 0;
        for (int j = 0; j < 5; j ++){
            printf("Оценка #%d: ", j+1);
            scanf("%d", &Stud1[i].GradeArray[j]);
            sum += Stud1[i].GradeArray[j];
        }
        Stud1[i].Sred = sum / 5.0;
        getchar();
	}

	/* Сортировка массива структур Student по полю Group (по возрастанию) */
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		for (int j = i + 1; j < MAX_STUDENTS; j++)
		{
			if (Stud1[i].Group > Stud1[j].Group)
			{
				stTemp = Stud1[i];
				Stud1[i] = Stud1[j];
				Stud1[j] = stTemp;
			}
		}
	}

    printf("\n\nСтуденты со средним баллом > 4\n");
	/* Вывод на экран фамилий студентов и номеров групп, у которых средний балл больше 4 */
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (Stud1[i].Sred > 4.0)
		{
			printf("\n%s из группы #%d", Stud1[i].Name, Stud1[i].Group);
			/* При наличие хотя бы одного такого студента выставляем флаг */
			is = 1;
		}
	}

	/* Если не найдено ни одного студента, удовлетворяющего условиям отбора выводим соответствующее сообщение */
	if (is == 0) printf("\nСтуденты со средним баллом успеваемости > 4 отсутствуют.");

    printf("\n\nСтуденты, имеющие только 4 или 5\n");
	is = 0;
	/* Вывод на экран фамилий студентов и номеров групп, у которых средний балл 4 или 5 */
	for (int i = 0; i < MAX_STUDENTS; i++)
	{   int sum = 0;
        for (int j = 0; j< 5; j++){
            if ((Stud1[i].GradeArray[j] == 4) || (Stud1[i].GradeArray[j] == 5.0)){
                sum++;
            }
        }
        if (sum == 5){
            printf("\n%s из группы #%d", Stud1[i].Name, Stud1[i].Group);
            is = 1;
        }

	}

	/* Если не найдено ни одного студента, удовлетворяющего условиям отбора выводим соответствующее сообщение */
	if (is == 0) printf("\nСтуденты, имеющие только 4 или 5 отсутствуют.");


    printf("\n\nСтуденты, имеющие хотя бы одну 2\n");
	is = 0;
	/* Вывод на экран фамилий студентов и номеров групп, у которых средний балл больше 4 */
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
        for (int j = 0; j< 5; j++){
            if (Stud1[i].GradeArray[j] == 2){
                printf("\n%s из группы #%d", Stud1[i].Name, Stud1[i].Group);
                is = 1;
            }
        }
	}

	/* Если не найдено ни одного студента, удовлетворяющего условиям отбора выводим соответствующее сообщение */
	if (is == 0) printf("\nСтуденты, имеющие хотя бы одну 2 отсутствуют.");

    printf("\n\n");
	return 0;

}