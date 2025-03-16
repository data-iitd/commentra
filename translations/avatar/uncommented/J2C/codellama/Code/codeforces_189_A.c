#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, maxn, a, b, c;
    int *arr, *dp;
    scanf("%d", &n);
    maxn = 4010;
    scanf("%d %d %d", &a, &b, &c);
    arr = (int *)malloc(3 * sizeof(int));
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    dp = (int *)malloc(maxn * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = arr[i]; j < maxn; j++)
        {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
