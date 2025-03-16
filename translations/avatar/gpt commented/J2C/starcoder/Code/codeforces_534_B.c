#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_VELOCITY 1150
#define MAX_TIME 100000
#define MAX_CHANGE 1000

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);
    long dp[MAX_TIME][MAX_VELOCITY];
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            dp[i][j] = -1e17;
        }
    }
    dp[0][v1] = v1;
    long sum = 0;
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX_VELOCITY) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j);
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }
    long ans = LONG_MIN;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            if (abs(j - v2) <= d) {
                ans = max(ans, dp[i][j] + v2);
            }
        }
    }
    printf("%ld\n", ans);
    return 0;
}

