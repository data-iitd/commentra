#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int time_value[N + 1][2];
    time_value[0][0] = -1;
    time_value[0][1] = -1;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i][0], &time_value[i][1]);
    }

    // Sort time_value based on their VAL (end time)
    qsort(time_value + 1, N, sizeof(time_value[0]), (int (*)(const void *, const void *))compare);

    int dp[N + 1][T];

    // Initialize dp matrix
    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
    }

    // Fill dp matrix
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t < T; t++) {
            // If current activity's start time is greater than t, then we cannot include it in the solution
            if (time_value[n][0] > t) {
                dp[n][t] = dp[n - 1][t];
            }
            // If current activity's start time is less than or equal to t, then we can include it in the solution
            else {
                dp[n][t] = MAX(dp[n - 1][t], time_value[n][1] + dp[n - 1][t - time_value[n][0]]);
            }
        }
    }

    // Calculate maximum value that can be obtained
    int val_acum = time_value[N][1];
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    // Calculate maximum value by considering all activities
    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n][1];
        t -= time_value[n + 1][0];
        if (t < 0) {
            break;
        } else {
            max_val = MAX(max_val, val_acum + dp[n - 1][t]);
        }
    }

    // Print the maximum value
    printf("%d\n", max_val);

    return 0;
}

int compare(const void *a, const void *b) {
    return ((int *)a)[1] - ((int *)b)[1];
}
