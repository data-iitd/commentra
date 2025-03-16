#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, maxn, *arr, *dp;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    maxn = 4010;
    arr = (int *)malloc(sizeof(int) * 3);
    dp = (int *)malloc(sizeof(int) * maxn);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for (int i = 0; i < maxn; i++)
        dp[i] = -1000000000;
    dp[0] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = arr[i]; j < maxn; j++)
        {
            if (dp[j] < dp[j - arr[i]] + 1)
                dp[j] = dp[j - arr[i]] + 1;
        }
    }
    printf("%d", dp[n]);
    return 0;
}

