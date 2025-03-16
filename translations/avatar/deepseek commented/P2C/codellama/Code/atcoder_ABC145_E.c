#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TIME 0
#define VAL 1

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    int time_value[N + 1][2];
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &time_value[i][TIME], &time_value[i][VAL]);
    }

    qsort(time_value + 1, N, sizeof(time_value[0]), cmp);

    int dp[N + 1][T];
    for (int t = 0; t < T; t++)
    {
        dp[0][t] = 0;
    }

    for (int n = 1; n <= N; n++)
    {
        dp[n][0] = 0;
        for (int t = 1; t < T; t++)
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

    int val_acum = time_value[N][VAL];
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    for (int n = N - 1; n >= 1; n--)
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

    printf("%d\n", max_val);

    return 0;
}

int cmp(const void *a, const void *b)
{
    return ((int *)b)[VAL] - ((int *)a)[VAL];
}

