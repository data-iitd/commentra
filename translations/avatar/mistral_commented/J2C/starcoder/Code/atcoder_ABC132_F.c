#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long mod = (long)1e9 + 7;
    int n, k;
    scanf("%d %d", &n, &k);
    int l = 1;
    int q = 0;
    int *len = (int*)malloc(sizeof(int) * (n + 1));
    while (l <= n)
    {
        int r = n / (n / l);
        len[q] = r - l + 1;
        q++;
        l = r + 1;
    }
    long *dp = (long*)malloc(sizeof(long) * (k * (q + 1)));
    for (int j = 1; j <= q; j++)
    {
        dp[j] = len[j - 1] + dp[j - 1];
    }
    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j <= q; j++)
        {
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1];
            dp[i * (q + 1) + j] %= mod;
        }
    }
    printf("%ld\n", dp[k * (q + 1) - 1]);
    return 0;
}

