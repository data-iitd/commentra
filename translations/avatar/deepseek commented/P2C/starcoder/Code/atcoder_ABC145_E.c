#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define TIME 0
#define VAL 1

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int time_value[N + 1][2];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i][TIME], &time_value[i][VAL]);
    }
    int dp[N + 1][T + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i <= T; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= T; j++) {
            if (time_value[i][TIME] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], time_value[i][VAL] + dp[i - 1][j - time_value[i][TIME]]);
            }
        }
    }
    int val_acum = time_value[N][VAL];
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];
    for (int i = N - 1; i >= 1; i--) {
        val_acum += time_value[i][VAL];
        t -= time_value[i + 1][TIME];
        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[i - 1][t]);
        }
    }
    printf("%d", max_val);
    return 0;
}

