
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);
    long dp[t - 1][1150];
    memset(dp, -1, sizeof(dp));
    dp[0][v1] = v1;
    long sum = 0;
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150) {
                    dp[i][j] = fmax(dp[i][j], dp[i - 1][j + x] + j);
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = fmax(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }
    long ans = LLONG_MIN;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            if (abs(j - v2) <= d) {
                ans = fmax(ans, dp[i][j] + v2);
            }
        }
    }
    printf("%ld\n", ans);
    return 0;
}
// END-OF-CODE