#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int pre = INT_MAX;
    int ans = 0;

    qsort(a, n, sizeof(int), compare);

    for (int j = 0; j < n; j++)
    {
        ans += max(0, min(pre - 1, a[j]));
        pre = min(pre - 1, a[j]);
    }

    printf("%d", ans);

    free(a);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

