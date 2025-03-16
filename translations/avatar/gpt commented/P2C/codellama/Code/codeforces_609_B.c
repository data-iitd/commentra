#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, res;
    scanf("%d %d", &n, &m);
    int *lst = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &lst[i]);
    int *l = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        l[i] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (lst[i] == lst[j])
            {
                l[i]++;
                l[j]++;
            }
        }
    }
    res = 0;
    for (i = 0; i < n; i++)
    {
        if (l[i] > 1)
            res += n - i - l[i];
        else
            res += n - i - 1;
    }
    printf("%d", res);
    return 0;
}
