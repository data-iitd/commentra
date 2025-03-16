
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    long long dp[n + 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = a[i] > dp[i + 1]? 0 : dp[i + 1] - a[i] + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", dp[i]);
    }
    printf("\n");
    return 0;
}

