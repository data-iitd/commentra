
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, res = 0;
    scanf("%d %d", &n, &m);
    int *lst = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &lst[i]);
    int *l = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        l[i] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (lst[i] == j)
            {
                l[j]++;
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (l[j] > 1)
            {
                res += n - i - l[j];
                l[j]--;
                break;
            }
            else
            {
                res += n - i - 1;
                break;
            }
        }
    }
    printf("%d", res);
    return 0;
}

