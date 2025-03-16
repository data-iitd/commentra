
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, l, r, x, t, next_val;
    int *out, *comp;

    scanf("%d %d", &n, &m);
    out = (int *)malloc(n * sizeof(int));
    comp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        out[i] = 0;
        comp[i] = i + 2;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &l, &r, &x);
        t = l;
        while (t <= r)
        {
            next_val = comp[t - 1];
            if (out[t - 1] == 0 && t != x)
            {
                out[t - 1] = x;
            }
            comp[t - 1] = r + 1;
            if (t >= x)
            {
                comp[t - 1] = x;
            }
            t = next_val;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", out[i]);
    }

    free(out);
    free(comp);

    return 0;
}

