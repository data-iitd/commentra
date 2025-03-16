#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, t, x, l, r;
    scanf("%d %d", &n, &m);
    int *out = (int *)malloc(sizeof(int) * n);
    int *comp = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        comp[i] = i + 2;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &l, &r, &x);
        t = l;
        while (t <= r)
        {
            int next_val = comp[t - 1];
            if (out[t - 1] == 0 && t!= x)
                out[t - 1] = x;
            comp[t - 1] = r + 1 if t >= x else x;
            t = next_val;
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", out[i]);
    printf("