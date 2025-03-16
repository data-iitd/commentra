#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, c, f;
    scanf("%d", &n);
    int l[n];
    for (i = 0; i < n; i++)
        scanf("%d", &l[i]);
    qsort(l, n, sizeof(int), compare);
    c = 0;
    for (i = 0; i < n; i++)
        if (l[i] > c)
            c++;
    printf("%d\n", c + 1);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

