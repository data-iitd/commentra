#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);
    int a[x], b[y], c[z];
    for (int i = 0; i < x; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < y; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < z; i++)
        scanf("%d", &c[i]);
    int ab[x * y];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            ab[i * y + j] = a[i] + b[j];
    int *ab_sorted = (int *)malloc(sizeof(int) * (x * y));
    memcpy(ab_sorted, ab, sizeof(int) * (x * y));
    qsort(ab_sorted, x * y, sizeof(int), (int (*)(const void *, const void *))qsort_cmp);
    int abc[k];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < z; j++)
            abc[i] = ab_sorted[i] + c[j];
    qsort(abc, k, sizeof(int), (int (*)(const void *, const void *))qsort_cmp);
    for (int i = 0; i < k; i++)
        printf("%d\n", abc[i]);
    return 0;
}

