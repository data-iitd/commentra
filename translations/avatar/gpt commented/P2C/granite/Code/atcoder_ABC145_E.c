
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int time_value[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &time_value[i][0], &time_value[i][1]);
    }

    int dp[N + 1][T];
    for (int n = 0; n <= N; n++) {
        for (int t = 0; t < T; t++) {
            dp[n][t] = -1;
        }
    }

    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }

    for (int n = 1; n <= N; n++) {
        for (int t = 1; t < T; t++) {
            if (time_value[n - 1][0] > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                dp[n][t] = max(dp[n - 1][t], time_value[n - 1][1] + dp[n - 1][t - time_value[n - 1][0]]);
            }
        }
    }

    int val_acum = time_value[N - 1][1];
    int t = T - 1 - time_value[N - 1][0];
    int max_val = val_acum + dp[N - 1][t];

    for (int n = N - 2; n >= 0; n--) {
        val_acum += time_value[n][1];
        t -= time_value[n][0];

        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[n][t]);
        }
    }

    printf("%d\n", max_val);

    return 0;
}
