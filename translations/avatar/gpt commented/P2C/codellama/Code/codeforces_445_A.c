#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        l[i] = (char *)malloc(m * sizeof(char));
        scanf("%s", l[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (l[i][j] == '.')
            {
                if ((i + j) & 1)
                {
                    l[i][j] = 'W';
                }
                else
                {
                    l[i][j] = 'B';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", l[i]);
    }

    for (int i = 0; i < n; i++)
    {
        free(l[i]);
    }
    free(l);

    return 0;
}

