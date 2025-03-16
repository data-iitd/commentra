
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, sum = 0, od = 0, ok = 0;
    scanf("%d", &n);
    int *lst = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &lst[i]);
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
                ok = !ok;
            }
        }
    }
    printf("%d", sum);
    return 0;
}

