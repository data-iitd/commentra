#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIME 0
#define VAL 1
#define N 100000
#define T 100000

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    int time_value[N][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &time_value[i][TIME], &time_value[i][VAL]);
    }
    int dp[N][T];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < t; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < t; j++) {
            if (time_value[i][TIME] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], time_value[i][VAL] + dp[i-1][j-time_value[i][TIME]]);
            }
        }
    }
    int val_acum = time_value[n-1][VAL];
    int t_acum = t - 1;
    int max_val = val_acum + dp[n-1][t_acum];
    for (int i = n-2; i >= 0; i--) {
        val_acum += time_value[i][VAL];
        t_acum -= time_value[i+1][TIME];
        if (t_acum < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[i-1][t_acum]);
        }
    }
    printf("%d\n", max_val);
    return 0;
}

