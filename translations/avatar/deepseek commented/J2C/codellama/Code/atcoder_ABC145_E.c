
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    int AB[N][2];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }

    int dp[N + 1][6001];
    for (int i = 0; i <= N; i++)
    {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++)
        {
            dp[i][timeAfterEat] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++)
        {
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            int time = AB[i - 1][0];
            int value = AB[i - 1][1];

            if (0 <= timeAfterEat - time && timeAfterEat - time < T)
            {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    int maxValue = 0;
    for (int i = 0; i <= N; i++)
    {
        maxValue = max(maxValue, dp[i][6000]);
    }

    printf("%d\n", maxValue);

    return 0;
}

