#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char a[1000];
    int i, j, k, count = 0;
    double result = 1;

    scanf("%s", a);

    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '1')
        {
            count++;
        }
    }

    if (count == 0)
    {
        printf("0");
    }
    else
    {
        for (i = 0, j = 0; a[i] != '\0'; i++)
        {
            if (a[i] == '1')
            {
                for (k = j; a[k] != '1' && a[k] != '\0'; k++)
                {
                    if (a[k] == '0')
                    {
                        count++;
                    }
                }
                result *= count;
                count = 0;
                j = k;
            }
        }
        printf("%.0lf", result);
    }

    return 0;
}

