#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, k;
    long ans;
    int *arr, *gen;

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(n * sizeof(int));
    gen = (int *)malloc(11 * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        gen[arr[i]]++;
    }

    ans = 0;
    for (i = 1; i <= m; i++)
    {
        for (k = 1; k <= m; k++)
        {
            if (i != k)
            {
                ans += (long)gen[i] * gen[k];
            }
        }
    }

    printf("%ld\n", ans / 2);

    free(arr);
    free(gen);

    return 0;
}

