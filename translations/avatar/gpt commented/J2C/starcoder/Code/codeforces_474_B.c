#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, res, x, arr[100000], q[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &q[i]);
    for (k = 0; k < m; k++)
    {
        res = 0;
        i = 0;
        j = n - 1;
        while (i <= j)
        {
            int md = (i + j) / 2;
            if (arr[md] == q[k])
                res = md;
            else if (arr[md] > q[k])
                j = md - 1;
            else
                i = md + 1;
        }
        printf("%d\n", res + 1);
    }
    return 0;
}

