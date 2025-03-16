
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char **arr;
    char **str;
    char a, b;
    int i, j;
    int res = 1;

    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    str = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(n * sizeof(char));
        str[i] = (char *)malloc(n * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = str[i][j];
        }
    }

    a = arr[0][0];
    b = arr[0][1];

    if (a == b)
    {
        printf("NO\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j || i + j == n - 1)
                {
                    if (arr[i][j] != a)
                    {
                        res = 0;
                        break;
                    }
                }
                else
                {
                    if (arr[i][j] != b)
                    {
                        res = 0;
                        break;
                    }
                }
            }
        }

        if (res)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

