
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k;
    int *l;
    scanf("%d", &n);
    l = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), compare);
    for (i = 0; i < n; i++)
    {
        if (l[i] + 1 < n && l[i] + 2 < n)
        {
            printf("YES\n");
            break;
        }
    }
    if (i == n)
    {
        printf("NO\n");
    }
    free(l);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

