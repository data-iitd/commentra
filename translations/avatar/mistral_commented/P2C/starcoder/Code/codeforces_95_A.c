#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int pya, i, j, k, l, m, n;
    char *arre[100000], *oString, *letter1, *letter2, *x;
    scanf("%d", &pya);
    for (i = 0; i < pya; i++)
    {
        arre[i] = (char *)malloc(100000 * sizeof(char));
        scanf("%s", arre[i]);
    }
    oString = (char *)malloc(100000 * sizeof(char));
    scanf("%s", oString);
    letter1 = (char *)malloc(100000 * sizeof(char));
    scanf("%s", letter1);
    letter2 = (char *)malloc(100000 * sizeof(char));
    letter2[0] = 'a';
    letter2[1] = '\0';
    if (letter1[0]!= 'a')
    {
        letter2[0] = 'b';
    }
    for (i = 0; i < strlen(oString); i++)
    {
        for (j = 0; j < pya; j++)
        {
            if (strstr(oString, arre[j])!= NULL)
            {
                for (k = 0; k < strlen(arre[j]); k++)
                {
                    if (oString[i + k] == arre[j][k])
                    {
                        m = 0;
                    }
                    else
                    {
                        m = 1;
                        break;
                    }
                }
                if (m == 0)
                {
                    for (l = 0; l < strlen(arre[j]); l++)
                    {
                        if (arre[j][l] == 'a')
                        {
                            n = 0;
                        }
                        else
                        {
                            n = 1;
                            break;
                        }
                    }
                    if (n == 0)
                    {
                        letter1[0] = 'a';
                    }
                    else
                    {
                        letter1[0] = 'b';
                    }
                    for (l = 0; l < strlen(arre[j]); l++)
                    {
                        if (arre[j][l] == 'a')
                        {
                            n = 0;
                        }
                        else
                        {
                            n = 1;
                            break;
                        }
                    }
                    if (n == 0)
                    {
                        letter2[0] = 'a';
                    }
                    else
                    {
                        letter2[0] = 'b';
                    }
                    for (l = 0; l < strlen(arre[j]); l++)
                    {
                        oString[i + l] = letter1[0];
                    }
                }
            }
        }
    }
    for (i = 0; i < strlen(oString); i++)
    {
        printf("%c", oString[i]);
    }
    printf("\n");
    return 0;
}

