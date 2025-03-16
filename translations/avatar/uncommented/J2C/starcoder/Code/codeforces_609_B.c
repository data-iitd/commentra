#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, arr[100000], gen[11];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        gen[arr[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            if (i!= k)
            {
                ans += (long long)gen[i] * gen[k];
            }
        }
    }
    printf("%lld\n", ans / 2);
    return 0;
}
