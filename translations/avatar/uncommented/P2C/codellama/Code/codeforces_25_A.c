
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, sum = 0;
    char *str, *p;
    int *list;

    scanf("%d", &n);
    str = (char *)malloc(n * sizeof(char));
    p = str;
    for (i = 0; i < n; i++)
    {
        scanf("%c", &str[i]);
    }
    list = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        list[i] = str[i] % 2;
    }
    for (i = 0; i < n; i++)
    {
        sum += list[i];
    }
    if (sum == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (list[i] == 1)
            {
                printf("%d", i + 1);
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (list[i] == 0)
            {
                printf("%d", i + 1);
                break;
            }
        }
    }
    free(str);
    free(list);
    return 0;
}

