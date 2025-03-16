#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char a[1000000], b[1000000], c[1000000], d[1000000], e[1000000], f[1000000], g[1000000], h[1000000], i[1000000], j[1000000], k[1000000], l[1000000], m[1000000], n[1000000], o[1000000], p[1000000], q[1000000], r[1000000], s[1000000], t[1000000], u[1000000], v[1000000], w[1000000], x[1000000], y[1000000], z[1000000];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    scanf("%s", d);
    scanf("%s", e);
    scanf("%s", f);
    scanf("%s", g);
    scanf("%s", h);
    scanf("%s", i);
    scanf("%s", j);
    scanf("%s", k);
    scanf("%s", l);
    scanf("%s", m);
    scanf("%s", n);
    scanf("%s", o);
    scanf("%s", p);
    scanf("%s", q);
    scanf("%s", r);
    scanf("%s", s);
    scanf("%s", t);
    scanf("%s", u);
    scanf("%s", v);
    scanf("%s", w);
    scanf("%s", x);
    scanf("%s", y);
    scanf("%s", z);
    int black = 0;
    int white = 0;
    int correct = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (b[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (c[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (d[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (e[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (f[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (g[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (h[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (i[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (j[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (k[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (l[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (m[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (n[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (o[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (p[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (q[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (r[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (s[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (t[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (u[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (v[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (w[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (x[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (y[i] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (z[j] == '#')
            {
                black += 1;
            }
            else
            {
                white += 1;
            }
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4)
            {
                correct = 1;
                break;
            }
            black = 0;
            white = 0;
        }
    }
    if (correct == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}