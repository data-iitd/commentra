#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a, b, *low, *high;

    scanf("%d", &n);

    low = (int *) malloc(n * sizeof(int));
    high = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        low[i] = a;
        high[i] = b;
    }

    qsort(low, n, sizeof(int), compare);
    qsort(high, n, sizeof(int), compare);

    if (n % 2)
    {
        printf("%d\n", high[(n+1)/2-1] - low[(n+1)/2-1] + 1);
    }
    else
    {
        printf("%d\n", (high[n/2-1] + high[n/2]) / 2 - (low[n/2-1] + low[n/2]) / 2 + 1);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

