#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_TIME 6000

int main() {
    int N, T;
    int AB[MAX_N][2];
    int dp[MAX_N + 1][MAX_TIME + 1];

    // Read the number of activities N and the time limit T
    scanf("%d %d", &N, &T);

    // Read the start time and value of each activity
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }

    // Initialize the dp array with -1
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= MAX_TIME; timeAfterEat++) {
            // Copy the previous value to the current position
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat]
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (timeAfterEat >= time && timeAfterEat < time + T) {
                if (dp[i - 1][timeAfterEat - time] != -1) {
                    dp[i][timeAfterEat] = (dp[i][timeAfterEat] > dp[i - 1][timeAfterEat - time] + value) ? dp[i][timeAfterEat] : dp[i - 1][timeAfterEat - time] + value;
                }
            }
        }
    }

    // Find the maximum value that can be obtained after eating all the activities
    int maxValue = 0;
    for (int timeAfterEat = 0; timeAfterEat <= MAX_TIME; timeAfterEat++) {
        if (dp[N][timeAfterEat] > maxValue) {
            maxValue = dp[N][timeAfterEat];
        }
    }

    // Print the maximum value
    printf("%d\n", maxValue);

    return 0;
}
