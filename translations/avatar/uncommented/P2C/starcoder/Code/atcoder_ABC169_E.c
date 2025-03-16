#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int low[n], high[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &low[i], &high[i]);
    }
    qsort(low, n, sizeof(int), compare);
    qsort(high, n, sizeof(int), compare);
    if(n % 2)
    {
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    }
    else
    {
        int hh = (high[(n) / 2 - 1] + high[(n) / 2]) / 2;
        int ll = (low[(n) / 2 - 1] + low[(n) / 2]) / 2;
        printf("%d\n", (hh - ll) * 2 + 1);
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

