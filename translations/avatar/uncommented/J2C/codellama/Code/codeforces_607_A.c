#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int max = 0;
    int n;
    int *beacon;
    int *dp;
    scanf("%d", &n);
    beacon = (int *)malloc(sizeof(int) * 1000001);
    dp = (int *)malloc(sizeof(int) * 1000001);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        scanf("%d", &beacon[a]);
    }
    if (beacon[0] != 0)
        dp[0] = 1;
    for (int i = 1; i < 1000001; i++)
    {
        if (beacon[i] != 0 && beacon[i] < i)
        {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        }
        else if (beacon[i] != 0)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
        max = max > dp[i] ? max : dp[i];
    }
    printf("%d", n - max);
    return 0;
}

