#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, i, j, maxn;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    maxn = 4010;
    int arr[3] = {a, b, c};
    int dp[maxn];
    for (i = 0; i < n; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for (i = 0; i < 3; i++) {
        for (j = arr[i]; j < maxn; j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }
    printf("%d", dp[n]);
    return 0;
}
