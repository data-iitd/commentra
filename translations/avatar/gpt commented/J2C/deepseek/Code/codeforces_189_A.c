#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, a, b, c;
    scanf("%d", &n);

    int maxn = 4010;
    int dp[maxn];

    for (int i = 0; i < maxn; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;

    scanf("%d %d %d", &a, &b, &c);

    int arr[] = {a, b, c};

    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j <= n; j++) {
            if (dp[j - arr[i]] != INT_MIN) {
                dp[j] = dp[j] > dp[j - arr[i]] + 1 ? dp[j] : dp[j - arr[i]] + 1;
            }
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
