#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_T 100
#define MAX_V 1150
#define MIN_VAL -(long)(1e17)

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);

    long dp[MAX_T][MAX_V];
    memset(dp, MIN_VAL, sizeof(dp));

    dp[0][v1] = v1;
    long sum = 0;

    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < MAX_V; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX_V) {
                    dp[i][j] = (dp[i][j] > dp[i - 1][j + x] + j) ? dp[i][j] : dp[i - 1][j + x] + j;
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = (dp[i][j] > dp[i - 1][j - x] + j) ? dp[i][j] : dp[i - 1][j - x] + j;
                }
            }
        }
    }

    long ans = -2147483648;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < MAX_V; j++) {
            if (abs(j - v2) <= d) {
                ans = (ans > dp[i][j] + v2) ? ans : dp[i][j] + v2;
            }
        }
    }

    printf("%ld\n", ans);
    return 0;
}
