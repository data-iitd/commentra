#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, c, max;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmpfunc);
    c = 1;
    max = 1;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= c)
            c++;
        else
            c = 1;
        if (c > max)
            max = c;
    }
    printf("%d\n", max);
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

