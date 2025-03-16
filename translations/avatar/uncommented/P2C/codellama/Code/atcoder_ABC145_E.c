#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TIME 0
#define VAL 1
int main()
{
    int N, T, i, t, n;
    int **dp;
    int **time_value;
    int val_acum, max_val;
    scanf("%d %d", &N, &T);
    time_value = (int **)malloc(sizeof(int *) * (N + 1));
    for (i = 0; i < N + 1; i++)
    {
        time_value[i] = (int *)malloc(sizeof(int) * 2);
    }
    for (i = 1; i < N + 1; i++)
    {
        scanf("%d %d", &time_value[i][TIME], &time_value[i][VAL]);
    }
    dp = (int **)malloc(sizeof(int *) * (N + 1));
    for (i = 0; i < N + 1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * T);
    }
    for (t = 0; t < T; t++)
    {
        dp[0][t] = 0;
    }
    for (n = 1; n < N + 1; n++)
    {
        dp[n][0] = 0;
        for (t = 1; t < T; t++)
        {
            if (time_value[n][TIME] > t)
            {
                dp[n][t] = dp[n - 1][t];
            }
            else
            {
                dp[n][t] = max(dp[n - 1][t], time_value[n][VAL] + dp[n - 1][t - time_value[n][TIME]]);
            }
        }
    }
    val_acum = time_value[N][VAL];
    t = T - 1;
    max_val = val_acum + dp[N - 1][t];
    for (n = N - 1; n > 0; n--)
    {
        val_acum += time_value[n][VAL];
        t -= time_value[n + 1][TIME];
        if (t < 0)
        {
            break;
        }
        else
        {
            max_val = max(max_val, val_acum + dp[n - 1][t]);
        }
    }
    printf("%d", max_val);
    return 0;
}