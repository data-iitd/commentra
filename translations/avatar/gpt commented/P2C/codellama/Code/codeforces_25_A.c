#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, sum = 0;
    char *str, *token;

    scanf("%d", &n);

    str = (char *)malloc(sizeof(char) * 100);
    scanf("%s", str);

    token = strtok(str, " ");
    while (token != NULL)
    {
        if (atoi(token) % 2 == 1)
        {
            sum++;
        }
        token = strtok(NULL, " ");
    }

    if (sum == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (str[i] == '1')
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
            if (str[i] == '0')
            {
                printf("%d", i + 1);
                break;
            }
        }
    }

    free(str);
    return 0;
}

