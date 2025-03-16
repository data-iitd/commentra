
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, md, res;
    int *arr, *q;

    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    arr[0] = 0;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }

    scanf("%d", &m);
    q = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
    {
        scanf("%d", &q[i]);
    }

    for (k = 0; k < m; k++)
    {
        i = 0;
        j = n;
        while (i <= j)
        {
            md = i + (j - i) / 2;
            if (arr[md] == q[k])
            {
                printf("%d\n", md);
                break;
            }
            else if (arr[md] > q[k])
            {
                j = md - 1;
            }
            else
            {
                i = md + 1;
            }
        }
    }

    free(arr);
    free(q);

    return 0;
}

