#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x[100000];
    scanf("%s", x);
    int s[100000];
    int tot[100000];
    int i, j, k, l, m, n, p, q, r, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < strlen(x); i++)
    {
        if (x[i] == 'O')
        {
            s[i] = 0;
        }
        else
        {
            s[i] = 1;
        }
    }
    for (i = 1; i < 13; i++)
    {
        if (12 % i == 0)
        {
            if (help(i, 12 / i, s))
            {
                tot[j] = (12 / i, i);
                j++;
            }
        }
    }
    printf("%d", j);
    for (i = 0; i < j; i++)
    {
        printf(" %dx%d", tot[i].first, tot[i].second);
    }
    printf("\n");
    return 0;
}

int help(int a, int b, int s[])
{
    int tot[100000];
    int i, j, k, l, m, n, p, q, r, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            tot[i * a + j] = s[i * a + j];
        }
    }
    for (i = 0; i < b; i++)
    {
        if (a == 1)
        {
            if (tot[i] == 12 / a)
            {
                return 1;
            }
        }
        else
        {
            if (tot[i * a] + tot[i * a + 1] == 12 / a)
            {
                return 1;
            }
        }
    }
    return 0;
}

