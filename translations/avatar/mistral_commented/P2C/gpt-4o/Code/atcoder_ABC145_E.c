#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_T 1000

typedef struct {
    int time;
    int value;
} Activity;

int compare(const void *a, const void *b) {
    return ((Activity *)a)->value - ((Activity *)b)->value;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    Activity time_value[MAX_N + 1];
    time_value[0].time = -1;
    time_value[0].value = -1;

    // Read time_value for each activity
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i].time, &time_value[i].value);
    }

    // Sort time_value based on their value (end time)
    qsort(time_value + 1, N, sizeof(Activity), compare);

    // Initialize dp matrix
    int dp[MAX_N + 1][MAX_T];
    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }
    dp[0][0] = 0;
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
    }

    // Fill dp matrix
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t < T; t++) {
            // If current activity's start time is greater than t, then we cannot include it in the solution
            if (time_value[n].time > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                // If current activity's start time is less than or equal to t, then we can include it in the solution
                dp[n][t] = dp[n - 1][t] > (time_value[n].value + dp[n - 1][t - time_value[n].time]) ? 
                           dp[n - 1][t] : 
                           (time_value[n].value + dp[n - 1][t - time_value[n].time]);
            }
        }
    }

    // Calculate maximum value that can be obtained
    int val_acum = time_value[N].value;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    // Calculate maximum value by considering all activities
    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n].value;
        t -= time_value[n + 1].time;
        if (t < 0) {
            break;
        } else {
            max_val = max_val > (val_acum + dp[n - 1][t]) ? max_val : (val_acum + dp[n - 1][t]);
        }
    }

    // Print the maximum value
    printf("%d\n", max_val);

    return 0;
}

// <END-OF-CODE>
