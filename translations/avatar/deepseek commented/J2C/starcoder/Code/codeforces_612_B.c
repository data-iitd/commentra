#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int dp[200001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &dp[i]);
    }
    long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }
    printf("%ld", ans);
    return 0;
}
