#include <stdio.h>
#include <string.h>
#include <locale.h>

int palindrome_check(char *str, int start, int end)
{
    char *locale = setlocale(LC_ALL, "");
    if (strlen(str) == 0) {
        printf("\nВведите строку: ");
        gets(str);
        int n= strlen(str);
        end = n - 1;
    }
    if(end-start==1 || start==end)
    {
        return 1;
    }
    else
    {
        if(str[start]==str[end])
        {
            return palindrome_check(str,start+1,end-1);
        }
        else
        {
            return 0;
        }
    }
}

int main() {

    char str[10];
    if(palindrome_check(str, 0, 10))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
