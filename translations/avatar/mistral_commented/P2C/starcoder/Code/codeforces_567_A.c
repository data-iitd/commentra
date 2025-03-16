#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inp, i, j, k, l, m, n, a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], x, y, z, w, t, u, v, s, r, q, p, o, n, m, l, k, j, i, x, y, z, w, t, u, v, s, r, q, p, o, n, m, l, k, j, i;
    scanf("%d", &inp);
    for (i = 0; i < inp; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < inp; i++)
    {
        if (i == 0)
        {
            b[i] = a[i + 1] - a[i];
            c[i] = a[inp - 1] - a[i];
            printf("%d %d\n", b[i], c[i]);
            continue;
        }
        if (i == inp - 1)
        {
            d[i] = a[inp - 1] - a[inp - 2];
            e[i] = a[inp - 1] - a[0];
            printf("%d %d\n", d[i], e[i]);
            continue;
        }
        if (a[i + 1] - a[i] > a[i] - a[i - 1])
        {
            f[i] = a[i + 1] - a[i];
            printf("%d ", f[i]);
        }
        else
        {
            g[i] = a[i] - a[i - 1];
            h[i] = a[i] - a[0];
            if (a[inp - 1] - a[i] > a[i] - a[0])
            {
                printf("%d %d\n", g[i], h[i]);
            }
            else
            {
                printf("%d %d\n", g[i], h[i]);
            }
        }
    }
    return 0;
}
