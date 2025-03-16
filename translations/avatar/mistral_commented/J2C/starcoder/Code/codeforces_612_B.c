#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, dp[200001];
    long ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &dp[i]);
    }
    for(i = 2; i <= n; i++)
    {
        ans += abs(dp[i] - dp[i-1]);
    }
    printf("%ld", ans);
    return 0;
}
