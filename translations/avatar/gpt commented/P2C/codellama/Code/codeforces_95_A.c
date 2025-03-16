#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pya;
    scanf("%d", &pya);
    char **arre = (char **)malloc(pya * sizeof(char *));
    for (int i = 0; i < pya; i++)
    {
        arre[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arre[i]);
    }
    char oString[100];
    scanf("%s", oString);
    char letter1, letter2;
    scanf("%c", &letter1);
    letter2 = (letter1 == 'a') ? 'b' : 'a';
    int valid[100];
    for (int i = 0; i < 100; i++)
    {
        valid[i] = 0;
    }
    int setcito[100];
    for (int i = 0; i < 100; i++)
    {
        setcito[i] = 0;
    }
    int wat = 0;
    for (int i = 0; i < pya; i++)
    {
        wat = 0;
        while (1)
        {
            int index = strstr(oString, arre[i]) - oString;
            if (index < 0)
            {
                break;
            }
            for (int j = index; j < index + strlen(arre[i]); j++)
            {
                setcito[j] = 1;
            }
            wat = index + strlen(arre[i]);
        }
    }
    for (int i = 0; i < 100; i++)
    {
        valid[i] = 0;
    }
    for (int i = 0; i < 100; i++)
    {
        if (setcito[i] == 1)
        {
            valid[i] = 1;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (valid[i] == 1)
        {
            if (oString[i] == letter1)
            {
                oString[i] = letter2;
            }
            else
            {
                oString[i] = letter1;
            }
        }
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%c", oString[i]);
    }
    printf("\n");
    return 0;
}
