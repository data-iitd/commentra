
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pya;
    scanf("%d", &pya);
    char arre[pya][100];
    for (int i = 0; i < pya; i++)
    {
        scanf("%s", arre[i]);
    }
    char oString[100];
    scanf("%s", oString);
    char letter1, letter2;
    scanf("%c", &letter1);
    letter2 = 'a';
    if (letter1 != 'a')
    {
        letter2 = 'b';
    }
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
        int index = 0;
        while (index >= 0)
        {
            index = strstr(oString, arre[i]) - oString;
            if (index >= 0)
            {
                for (int j = index; j < index + strlen(arre[i]); j++)
                {
                    setcito[j] = 1;
                }
                wat = index + 1;
            }
        }
    }
    for (int i = 0; i < strlen(oString); i++)
    {
        if (setcito[i] == 1)
        {
            if (oString[i] >= 'a' && oString[i] <= 'z')
            {
                oString[i] = letter1;
            }
            else
            {
                oString[i] = letter2;
            }
        }
    }
    printf("%s", oString);
    return 0;
}
