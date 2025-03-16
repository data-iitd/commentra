// Include necessary C utility libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store the start time and value of each activity
struct Activity {
    int startTime;
    int value;
};

// Define a function to sort the activities based on their start time
int compareActivities(const void *a, const void *b) {
    struct Activity *activityA = (struct Activity *) a;
    struct Activity *activityB = (struct Activity *) b;
    return activityA->startTime - activityB->startTime;
}

// Define a function to calculate the maximum value that can be obtained after eating all the activities
int calculateMaxValue(struct Activity *activities, int N, int T) {
    // Initialize a 2D array dp to store the maximum value that can be obtained up to a certain time after eating an activity
    int **dp = (int **) malloc(N + 1 * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int *) malloc(6001 * sizeof(int));
    }

    // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat] > dp[i][timeAfterEat] ? dp[i - 1][timeAfterEat] : dp[i][timeAfterEat];

            // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
            int time = activities[i - 1].startTime;
            int value = activities[i - 1].value;
            if (timeAfterEat >= time && timeAfterEat < time + T) {
                dp[i][timeAfterEat] = dp[i - 1][timeAfterEat - time] + value > dp[i][timeAfterEat] ? dp[i - 1][timeAfterEat - time] + value : dp[i][timeAfterEat];
            }
        }
    }

    // Print the maximum value that can be obtained after eating all the activities
    int maxValue = 0;
    for (int i = 0; i <= N; i++) {
        maxValue = maxValue > dp[i][6000] ? maxValue : dp[i][6000];
    }
    printf("%d\n", maxValue);

    // Free the memory allocated for the dp array
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);

    return maxValue;
}

// Main function to start the program
int main() {
    // Initialize a variable to store the number of activities N and the time limit T
    int N, T;

    // Read the number of activities N and the time limit T from the console
    scanf("%d %d", &N, &T);

    // Initialize an array to store the start time and value of each activity
    struct Activity activities[N];

    // Read the start time and value of each activity from the console and store it in the activities array
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &activities[i].startTime, &activities[i].value);
    }

    // Sort the activities array based on their start time
    qsort(activities, N, sizeof(struct Activity), compareActivities);

    // Calculate the maximum value that can be obtained after eating all the activities
    calculateMaxValue(activities, N, T);

    return 0;
}

