#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, mx, a, b, c, d, e, f, g, h, dp[1000010];

    scanf("%d", &n);

    for (i = 0; i < 1000010; i++)
        dp[i] = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        dp[a] = b;
    }

    if (dp[0] > 0)
        dp[0] = 1;

    mx = 0;

    for (i = 1; i < 1000010; i++)
    {
        if (dp[i] == 0)
            dp[i] = dp[i - 1];
        else if (dp[i] >= i)
            dp[i] = 1;
        else
        {
            k = i - dp[i] - 1;
            dp[i] = dp[k] + 1;
        }

        if (dp[i] > mx)
            mx = dp[i];
    }

    printf("%d\n", n - mx);

    return 0;
}

