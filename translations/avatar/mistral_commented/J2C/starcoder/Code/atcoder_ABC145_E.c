#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

// Function to find the maximum value that can be obtained after eating all the activities
int maxEatingTime(int N, int T, int AB[][2]) {
    // Initialize a 2D array dp to store the maximum value that can be obtained up to a certain time after eating an activity
    int dp[N + 1][6001];

    // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (timeAfterEat >= time && timeAfterEat < time + T) {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Return the maximum value that can be obtained after eating all the activities
    return dp[N][6000];
}

// Main function to start the program
int main(void) {
    // Read the number of activities N and the time limit T from the console
    int N, T;
    scanf("%d %d", &N, &T);

    // Initialize a 2D array AB to store the start time and value of each activity
    int AB[N][2];

    // Read the start time and value of each activity from the console and store it in the AB array
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }

    // Print the maximum value that can be obtained after eating all the activities
    printf("%d\n", maxEatingTime(N, T, AB));

    return 0;
}

