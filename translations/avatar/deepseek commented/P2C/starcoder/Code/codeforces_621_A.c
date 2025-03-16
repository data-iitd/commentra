
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0, od = 0, ok = 0;
    scanf("%d", &n);
    int *lst = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &lst[i]);
    }
    qsort(lst, n, sizeof(int), compare);
    for (i = 0; i < n; i++)
    {
        if (lst[i] & 1)
        {
            od++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (lst[i] % 2 == 0)
        {
            sum += lst[i];
        }
        else
        {
            if (ok || od > 1)
            {
                sum += lst[i];
                od--;
                ok =!ok;
            }
        }
    }
    printf("%d", sum);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

