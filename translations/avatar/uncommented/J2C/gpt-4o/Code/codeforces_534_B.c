#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_VELOCITY 1150
#define MIN_VALUE -(long long)(1e17)

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);

    long long dp[t - 1][MAX_VELOCITY];
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            dp[i][j] = MIN_VALUE;
        }
    }
    dp[0][v1] = v1;

    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX_VELOCITY) {
                    dp[i][j] = dp[i][j] > dp[i - 1][j + x] + j ? dp[i][j] : dp[i - 1][j + x] + j;
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = dp[i][j] > dp[i - 1][j - x] + j ? dp[i][j] : dp[i - 1][j - x] + j;
                }
            }
        }
    }

    long long ans = LLONG_MIN;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            if (abs(j - v2) <= d) {
                ans = ans > dp[i][j] + v2 ? ans : dp[i][j] + v2;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
