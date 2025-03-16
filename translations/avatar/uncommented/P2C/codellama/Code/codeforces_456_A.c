
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, a[100][2], b[100][2], c[100][2], d[100][2], e[100][2], f[100][2], g[100][2], h[100][2], m[100][2], n[100][2], o[100][2], p[100][2], q[100][2], r[100][2], s[100][2], t[100][2], u[100][2], v[100][2], w[100][2], x[100][2], y[100][2], z[100][2];
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
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (m[i][1] > m[j][1])
            {
                n[i][0] = m[i][0];
                n[i][1] = m[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (n[i][1] > n[j][1])
            {
                o[i][0] = n[i][0];
                o[i][1] = n[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (o[i][1] > o[j][1])
            {
                p[i][0] = o[i][0];
                p[i][1] = o[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i][1] > p[j][1])
            {
                q[i][0] = p[i][0];
                q[i][1] = p[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][1] > q[j][1])
            {
                r[i][0] = q[i][0];
                r[i][1] = q[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (r[i][1] > r[j][1])
            {
                s[i][0] = r[i][0];
                s[i][1] = r[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i][1] > s[j][1])
            {
                t[i][0] = s[i][0];
                t[i][1] = s[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (t[i][1] > t[j][1])
            {
                u[i][0] = t[i][0];
                u[i][1] = t[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (u[i][1] > u[j][1])
            {
                v[i][0] = u[i][0];
                v[i][1] = u[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][1] > v[j][1])
            {
                w[i][0] = v[i][0];
                w[i][1] = v[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (w[i][1] > w[j][1])
            {
                x[i][0] = w[i][0];
                x[i][1] = w[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (x[i][1] > x[j][1])
            {
                y[i][0] = x[i][0];
                y[i][1] = x[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (y[i][1] > y[j][1])
            {
                z[i][0] = y[i][0];
                z[i][1] = y[i][1];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (z[i][1] > z[j][1])
            {
                printf("Happy Alex\n");
                break;
            }
        }
    }
    return 0;
}