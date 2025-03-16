
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, c[100000], d[100000], count = 0;
    char s[100000][100000];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
            {
                k = j;
            }
            if (s[i][j] == 'G')
            {
                l = j;
            }
        }
        c[i] = k - l;
    }

    for (i = 0; i < n; i++)
    {
        if (c[i] >= 0)
        {
            count++;
        }
    }

    if (count == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d", count);
    }

    return 0;
}

