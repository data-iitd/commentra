#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, min;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    min = a[0];
    for (i = 0; i < n; i++)
        if (a[i] % min!= 0)
        {
            printf("-1\n");
            return 0;
        }
    printf("%d\n", min);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

