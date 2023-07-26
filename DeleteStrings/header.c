int chislo_strok(int *n)
{

    printf("Введите количество строк в тексте: ");
    scanf("%d%*c", n);

    while (*n > MSTR)
    {

        printf("Range you number [1..%d]\n", MSTR);

        printf("You number is: ");

        scanf("%d%*c", n);
    }
}

void input_str(char string[][MAXLEN], int n)
{

    char *simvol = NULL;

    for (int s = 0; s < n; s++)
    {
        fgets(string[s], MAXLEN, stdin);
        simvol = strchr(string[s], '\n');
        if (simvol != NULL)
            *simvol = '\0';
    }
}

void delete_word(int n, char string[][MAXLEN], char strout[][MAXLEN])
{

    printf("\n");
    char in[MAXLEN];

    for (int i = 0; i < n; i++)
    {
        char out[MAXLEN] = "";
        int test = 0;
        strcpy(in, string[i]);
        char *p = strtok(in, " ");

        while (p)
        {

            test++;
            if (test % 2 == 1)
            {
                strcat(out, p);
                strcat(out, " ");
            }
            p = strtok(NULL, " ");
        }

        strcat(out, "\n");
        strcpy(strout[i], out);
        puts(strout[i]);
    }
    printf("-----------------------------------\n");
}