
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);

    long long dp[t - 1][1150];
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            dp[i][j] = LLONG_MIN;
        }
        dp[i][v1] = v1;
    }

    long long sum = 0;
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                dp[i][j] = fmax(dp[i][j], dp[i - 1][j + x] + j);
            }
            for (int x = d; x >= 0; x--) {
                dp[i][j] = fmax(dp[i][j], dp[i - 1][j - x] + j);
            }
        }
        sum += dp[i][1149];
    }

    long long ans = LLONG_MIN;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            if (labs(j - v2) <= d) {
                ans = fmax(ans, dp[i][j] + v2);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
