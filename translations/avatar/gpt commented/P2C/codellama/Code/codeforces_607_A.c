#include <stdio.h>

int main()
{
    int n, i, j, l[1000010], dp[1000010], mx;

    scanf("%d", &n);

    for (i = 0; i < 1000010; i++)
    {
        l[i] = 0;
        dp[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        l[a] = b;
    }

    if (l[0] > 0)
    {
        dp[0] = 1;
    }

    mx = 0;

    for (i = 1; i < 1000010; i++)
    {
        if (l[i] == 0)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            if (l[i] >= i)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = dp[i - l[i] - 1] + 1;
            }
        }

        if (dp[i] > mx)
        {
            mx = dp[i];
        }
    }

    printf("%d", n - mx);

    return 0;
}

