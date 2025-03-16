
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j, cx, cy, ch;
    int *x, *y, *h;

    scanf("%d", &n);

    x = (int *)malloc(n * sizeof(int));
    y = (int *)malloc(n * sizeof(int));
    h = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &x[i], &y[i], &h[i]);
    }

    for (i = 0; i <= 100; i++)
    {
        for (j = 0; j <= 100; j++)
        {
            ch = -1;
            for (int k = 0; k < n; k++)
            {
                if (h[k] > 0)
                {
                    ch = abs(x[k] - i) + abs(y[k] - j) + h[k];
                    break;
                }
            }
            for (int k = 0; k < n; k++)
            {
                if (h[k] != max(ch - abs(x[k] - i) - abs(y[k] - j), 0))
                {
                    ch = -1;
                    break;
                }
            }
            if (ch > 0)
            {
                printf("%d %d %d\n", i, j, ch);
            }
        }
    }

    free(x);
    free(y);
    free(h);

    return 0;
}

