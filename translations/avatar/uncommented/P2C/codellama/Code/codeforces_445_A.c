
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m;
    char **l;
    char *s;
    int i, j;

    scanf("%d %d", &n, &m);
    l = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        l[i] = (char *)malloc(m * sizeof(char));
        scanf("%s", l[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (l[i][j] == '.')
            {
                if ((i + j) & 1)
                    l[i][j] = 'W';
                else
                    l[i][j] = 'B';
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", l[i]);
    }
    return 0;
}

