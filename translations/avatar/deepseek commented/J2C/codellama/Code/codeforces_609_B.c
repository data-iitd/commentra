
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, k, arr[1000], gen[11] = {0};
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        gen[arr[i]]++;
    }
    long long ans = 0;
    for (i = 1; i <= m; i++)
    {
        for (k = 1; k <= m; k++)
        {
            if (i != k)
            {
                ans += (long long)gen[i] * gen[k];
            }
        }
    }
    printf("%lld\n", ans / 2);
    return 0;
}

