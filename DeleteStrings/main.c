#include "header.h"
#include "header.c"

int main(void) {

int n;

char str[MSTR][MAXLEN];

char vix[MSTR][MAXLEN];

chislo_strok(&n);

printf("Введите текст из %d строк: \n", n);

input_str(str, n);
printf("\nУдаление из строк слова с четными номерами...\n");
printf("\n-----------------------------------\n");

delete_word(n, str, vix);

return (0);

}