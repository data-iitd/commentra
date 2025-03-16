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
    qsort(ab, x * y, sizeof(int), compare);
    int abc[k];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < z; j++)
            abc[i] = ab[i] + c[j];
    qsort(abc, k, sizeof(int), compare);
    for (int i = 0; i < k; i++)
        printf("%d\n", abc[i]);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

