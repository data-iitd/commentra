#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, m, q, i;
    int *x;

    scanf("%d %d", &n, &d);
    x = (int *)malloc(n * sizeof(int));
    m = 0;
    q = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        if (x[i] >= x[i + 1])
        {
            q = (x[i] - x[i + 1]) / d + 1;
            m = m + q;
            x[i + 1] = x[i + 1] + q * d;
        }
    }

    printf("%d\n", m);

    return 0;
}

