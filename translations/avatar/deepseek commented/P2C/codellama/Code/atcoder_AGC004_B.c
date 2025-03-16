#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, i, j, k, m;
    int a[100000], b[100000][100000];

    scanf("%d %d", &n, &x);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        m = a[i];
        for (j = 0; j < n; j++)
        {
            k = i - j;
            if (k < 0)
            {
                k += n;
            }
            m = min(m, a[k]);
            b[j][i] = m;
        }
    }

    m = 1000000000;
    for (i = 0; i < n; i++)
    {
        m = min(m, sum(b[i]) + x * i);
    }

    printf("%d", m);

    return 0;
}

