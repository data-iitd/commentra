
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, i, a, q, m;
    int *x;
    scanf("%d %d", &n, &d);
    x = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (a = 0; a < n - 1; a++)
    {
        if (x[a] >= x[a + 1])
        {
            q = (x[a] - x[a + 1]) / d + 1;
            m = m + q;
            x[a + 1] = x[a + 1] + q * d;
        }
    }
    printf("%d", m);
    return 0;
}

