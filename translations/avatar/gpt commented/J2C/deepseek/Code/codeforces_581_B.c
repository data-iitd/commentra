#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long dp[n + 1];
    memset(dp, -1, sizeof(dp));

    dp[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = (dp[i + 1] > a[i]) ? dp[i + 1] : a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        } else {
            printf("%lld ", dp[i + 1] - a[i] + 1);
        }
    }
    printf("\n");

    return 0;
}
