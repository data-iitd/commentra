#include <stdio.h>
#include <stdlib.h>

#define TIME 0
#define VAL 1

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int time_value[N + 1][2];
    time_value[0][TIME] = -1;
    time_value[0][VAL] = -1;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i][TIME], &time_value[i][VAL]);
    }

    // Sort the time_value array based on the value (VAL)
    // This is a simple bubble sort for demonstration purposes
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (time_value[i][VAL] < time_value[j][VAL]) {
                int temp_time = time_value[i][TIME];
                int temp_val = time_value[i][VAL];
                time_value[i][TIME] = time_value[j][TIME];
                time_value[i][VAL] = time_value[j][VAL];
                time_value[j][TIME] = temp_time;
                time_value[j][VAL] = temp_val;
            }
        }
    }

    int dp[N + 1][T + 1];
    for (int t = 0; t <= T; t++) {
        dp[0][t] = 0;
    }

    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
        for (int t = 1; t <= T; t++) {
            if (time_value[n][TIME] > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                dp[n][t] = (dp[n - 1][t] > time_value[n][VAL] + dp[n - 1][t - time_value[n][TIME]] ? dp[n - 1][t] : time_value[n][VAL] + dp[n - 1][t - time_value[n][TIME]]);
            }
        }
    }

    int val_acum = time_value[N][VAL];
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n][VAL];
        t -= time_value[n + 1][TIME];
        if (t < 0) {
            break;
        } else {
            max_val = (max_val > val_acum + dp[n - 1][t] ? max_val : val_acum + dp[n - 1][t]);
        }
    }

    printf("%d\n", max_val);
    return 0;
}
