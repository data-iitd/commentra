#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int pya;
    char arre[100000][100000];
    char oString[100000];
    char letter1, letter2;
    int valid[100000];
    int setcito[100000];
    int i, j, wat, index;

    scanf("%d", &pya);
    for (i = 0; i < pya; i++)
    {
        scanf("%s", arre[i]);
    }
    scanf("%s", oString);
    letter1 = getchar();
    letter2 = 'a' == letter1? 'b' : 'a';
    for (i = 0; i < strlen(oString); i++)
    {
        valid[i] = 0;
    }
    for (i = 0; i < pya; i++)
    {
        for (j = 0; j < strlen(oString); j++)
        {
            if (0 == valid[j] && 0 == strncmp(oString + j, arre[i], strlen(arre[i])))
            {
                valid[j] = 1;
            }
        }
    }
    for (i = 0; i < strlen(oString); i++)
    {
        setcito[i] = 0;
    }
    for (i = 0; i < strlen(oString); i++)
    {
        if (1 == valid[i])
        {
            for (j = i; j < strlen(oString); j++)
            {
                if (0 == setcito[j] && 0 == strncmp(oString + j, arre[i], strlen(arre[i])))
                {
                    for (wat = j; wat < strlen(oString); wat++)
                    {
                        setcito[wat] = 1;
                    }
                }
            }
        }
    }
    for (i = 0; i < strlen(oString); i++)
    {
        if (0 == setcito[i])
        {
            continue;
        }
        if (oString[i] == letter1)
        {
            oString[i] = letter2;
        }
        else if (oString[i] == letter2)
        {
            oString[i] = letter1;
        }
    }
    for (i = 0; i < strlen(oString); i++)
    {
        printf("%c", oString[i]);
    }
    printf("\n");
    return 0;
}

