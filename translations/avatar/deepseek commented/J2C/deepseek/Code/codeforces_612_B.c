#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int dp[200001];

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        dp[num] = i;
    }

    long long ans = 0;

    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }

    printf("%lld\n", ans);
    return 0;
}
