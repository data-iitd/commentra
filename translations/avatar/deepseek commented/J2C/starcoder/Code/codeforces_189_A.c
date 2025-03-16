
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, maxn, a, b, c, i, j, arr[3], dp[4010];
    scanf("%d", &n);
    scanf("%d", &maxn);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for(i=0; i<maxn; i++)
        dp[i] = -1;
    dp[0] = 0;
    for(i=0; i<3; i++)
    {
        for(j=arr[i]; j<maxn; j++)
        {
            if(dp[j-arr[i]]!= -1)
            {
                if(dp[j] == -1)
                    dp[j] = dp[j-arr[i]] + 1;
                else
                    dp[j] = (dp[j] > dp[j-arr[i]] + 1)? dp[j] : dp[j-arr[i]] + 1;
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}

