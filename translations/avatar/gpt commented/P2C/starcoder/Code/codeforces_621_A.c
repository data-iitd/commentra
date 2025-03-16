#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, od, sum, ok;
    scanf("%d", &n);
    int *lst = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &lst[i]);
    qsort(lst, n, sizeof(int), compare);
    od = 0;
    for (i = 0; i < n; i++)
        od += (lst[i] & 1);
    sum = 0;
    ok = 0;
    for (i = 0; i < n; i++)
    {
        if (lst[i] % 2 == 0)
            sum += lst[i];
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
    printf("%d\n", sum);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

