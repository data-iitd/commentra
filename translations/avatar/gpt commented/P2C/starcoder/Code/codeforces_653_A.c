#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
    {
        if (l[i] + 1 < n && l[i] + 2 < n)
        {
            printf("YES");
            break;
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

