#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *a, char *b, char *c, char *d)
{
  int size = strlen(a) + strlen(b) + strlen(c) + strlen(d) + 1;
  char *str = malloc(size);
  strcpy (str, a);
  strcat (str, b);
  strcat (str, c); 
  strcat (str, d); 

  return str;
}

char* GetDec(int num)
{
  char *numString;
  switch (num) {
      case 0: numString = "десять ";
      break;
      case 1: numString = "одинадцать ";
      break;
      case 2: numString = "двенадцать ";
      break;
      case 3: numString = "тринадцать ";
      break;
      case 4: numString = "четырнадцать ";
      break;
      case 5: numString = "пятнадцать ";
      break;
      case 6: numString = "шестнадцать ";
      break;
      case 7: numString = "семнадцать ";
      break;
      case 8: numString = "восемнадцать ";
      break;
      case 9: numString = "девятнадцать ";
      break;
      default:
      break;
}
  return numString;
}

char* NumToString(int num, int isThousand)
{
  char *numString;
  int ed = 0, dec = 0, sot = 0;
  if (num > 0)
  {
      ed = num % 10;
      if (num >= 10)
        dec = (num % 100 - ed) / 10;
      if (num >= 100)
        sot = (num % 1000 - num % 100) / 100;
  }
  char *edChar, *decChar, *sotChar;
  switch (ed) {
      case 0: edChar = ""; break;
      case 1:
        if (isThousand == 0)
          edChar = "один ";
        else 
          edChar = "одна ";
          break;
      case 2: 
        if (isThousand == 0)
          edChar = "два ";
        else 
          edChar = "две ";
          break;
      case 3: edChar = "три "; break;
      case 4: edChar = "четыре "; break;
      case 5: edChar = "пять "; break;
      case 6: edChar = "шесть "; break;
      case 7: edChar = "семь "; break;
      case 8: edChar = "восемь "; break;
      case 9: edChar = "девять "; break;
      default: break;
}
  switch (dec) {
      case 0: decChar = ""; break;
      case 1: decChar = GetDec(ed); break;
      case 2: decChar = "двадцать "; break;
      case 3: decChar = "тридцать "; break;
      case 4: decChar = "сорок "; break;
      case 5: decChar = "пятьдесят "; break;
      case 6: decChar = "шестьдесят "; break;
      case 7: decChar = "семьдесят "; break;
      case 8: decChar = "восемьдесят "; break;
      case 9: decChar = "девяносто "; break;
      default: break;
}
  switch (sot) {
      case 0: sotChar = ""; break;
      case 1: sotChar = "сто "; break;
      case 2: sotChar = "двести "; break;
      case 3: sotChar = "триста "; break;
      case 4: sotChar = "четыреста "; break;
      case 5: sotChar = "пятьсот "; break;
      case 6: sotChar = "шестьсот "; break;
      case 7: sotChar = "семьсот "; break;
      case 8: sotChar = "восемьсот "; break;
      case 9: sotChar = "девятьсот "; break;
      default: break;
}

if (dec != 1) {
    numString = concat(sotChar, decChar, edChar, "");
}
else {
    numString = concat(sotChar, decChar, "", "");
}
  return  numString;
}

int main()
{
      float numFloat;
      printf("Введите число (c двумя знаками после запятой) => ");
      scanf("%f", &numFloat);
      int num = (int) numFloat;
      int penny = (numFloat - num) * 100;
      const char* str = "";
      int hundreds = 0, thousands = 0, millions = 0, milliards = 0, lastNum;
      char *hChar = "", *tChar = "", *milChar = "", *mildChar = "", *nameNum, *pennyChar;
      if (num > 0) {
            hundreds = num % 1000;
            hChar = NumToString(hundreds, 0);
            if (num >= 1000) {
                thousands = (num % 1000000 - hundreds) / 1000;
                lastNum = thousands % 10;
                if (lastNum == 0)
                    nameNum = "";
                else if (lastNum == 1 && thousands % 100 != 11)
                    nameNum = "тысяча ";
                else if (lastNum >= 2 && lastNum <= 4 && thousands % 100 != 12)
                    nameNum = "тысячи ";
                else 
                    nameNum = "тысяч ";
                tChar = concat(NumToString(thousands, 1), nameNum, "", "");
            }
            if (num >= 1000000) {
                millions = (num % 1000000000 - num % 1000000) / 1000000;
                lastNum = millions % 10;
                if (lastNum == 0)
                    nameNum = "";
                else if (lastNum == 1 && millions % 100 != 11)
                    nameNum = "миллион ";
                else if (lastNum >= 2 && lastNum <= 4 && millions % 100 != 12)
                    nameNum = "миллиона ";
                else 
                    nameNum = "миллионов ";
                milChar = concat(NumToString(millions, 0), nameNum, "", "");
            }
            if (num >= 1000000000) {
                milliards = (num % 1000000000000 - num % 1000000000) / 1000000000;
                lastNum = milliards % 10;
                if (lastNum == 0)
                    nameNum = "";
                else if (lastNum == 1 && milliards % 100 != 11)
                    nameNum = "миллиард ";
                else if (lastNum >= 2 && lastNum <= 4 && milliards % 100 != 12)
                    nameNum = "миллиарда ";
                else 
                    nameNum = "миллиардов ";
                mildChar = concat(NumToString(milliards, 0), nameNum, "", "");
            }
      }
      str = concat(mildChar, milChar, tChar, hChar);
      printf("%s", str);
      lastNum = penny % 10;
      if (lastNum == 0)
        nameNum = "ноль копеек";
      else if (lastNum == 1 && penny != 11)
        nameNum = "копейка ";
      else if (lastNum >= 2 && lastNum <= 4 && penny != 12)
        nameNum = "копейки ";
      else 
        nameNum = "копеек ";
      pennyChar = concat("руб, ", NumToString(penny, 1), nameNum, "");
      printf("%s", pennyChar);
    return 0;
}
