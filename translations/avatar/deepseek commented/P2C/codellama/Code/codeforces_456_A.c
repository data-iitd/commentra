
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, a[100][2], b[100][2], c[100][2], d[100][2], e[100][2], f[100][2], g[100][2], h[100][2], m[100][2];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][1] > a[j][1])
            {
                b[i][0] = a[i][0];
                b[i][1] = a[i][1];
            }
            else
            {
                b[i][0] = a[j][0];
                b[i][1] = a[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][1] > b[j][1])
            {
                c[i][0] = b[i][0];
                c[i][1] = b[i][1];
            }
            else
            {
                c[i][0] = b[j][0];
                c[i][1] = b[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i][1] > c[j][1])
            {
                d[i][0] = c[i][0];
                d[i][1] = c[i][1];
            }
            else
            {
                d[i][0] = c[j][0];
                d[i][1] = c[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][1] > d[j][1])
            {
                e[i][0] = d[i][0];
                e[i][1] = d[i][1];
            }
            else
            {
                e[i][0] = d[j][0];
                e[i][1] = d[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (e[i][1] > e[j][1])
            {
                f[i][0] = e[i][0];
                f[i][1] = e[i][1];
            }
            else
            {
                f[i][0] = e[j][0];
                f[i][1] = e[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (f[i][1] > f[j][1])
            {
                g[i][0] = f[i][0];
                g[i][1] = f[i][1];
            }
            else
            {
                g[i][0] = f[j][0];
                g[i][1] = f[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (g[i][1] > g[j][1])
            {
                h[i][0] = g[i][0];
                h[i][1] = g[i][1];
            }
            else
            {
                h[i][0] = g[j][0];
                h[i][1] = g[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (h[i][1] > h[j][1])
            {
                m[i][0] = h[i][0];
                m[i][1] = h[i][1];
            }
            else
            {
                m[i][0] = h[j][0];
                m[i][1] = h[j][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (m[i][1] > m[j][1])
            {
                printf("Happy Alex\n");
                break;
            }
            else
            {
                printf("Poor Alex\n");
            }
        }
    }
    return 0;
}

