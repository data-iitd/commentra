#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, max, a, b, dp[1000001];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        dp[a] = b;
    }
    if(dp[0]!= 0)
        dp[0] = 1;
    for(i = 1; i < 1000001; i++)
    {
        if(dp[i]!= 0 && dp[i] < i)
            dp[i] = dp[i - dp[i] - 1] + 1;
        else if(dp[i]!= 0)
            dp[i] = 1;
        else
            dp[i] = dp[i - 1];
        max = (max > dp[i])? max : dp[i];
    }
    printf("%d\n", n - max);
    return 0;
}
