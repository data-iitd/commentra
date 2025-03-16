#include <stdio.h>
#include <stdlib.h>

// Structure to hold the start time and value of each activity
typedef struct {
    int start;
    int value;
} Activity;

// Comparison function for sorting activities by start time
int compare(const void *a, const void *b) {
    return ((Activity *)a)->start - ((Activity *)b)->start;
}

int main() {
    // Read the number of activities N and the time limit T
    int N, T;
    scanf("%d %d", &N, &T);

    // Allocate memory for activities
    Activity *AB = (Activity *)malloc(N * sizeof(Activity));

    // Read the start time and value of each activity
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i].start, &AB[i].value);
    }

    // Sort the activities based on the start time
    qsort(AB, N, sizeof(Activity), compare);

    // Allocate memory for the dp array
    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int *)malloc(6001 * sizeof(int));
    }

    // Initialize dp array
    for (int i = 0; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = 0;
        }
    }

    // Calculate the maximum value that can be obtained
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            // If the timeAfterEat is within the time limit T after the start time of activity i
            int time = AB[i - 1].start;
            int value = AB[i - 1].value;
            if (timeAfterEat >= time && timeAfterEat < time + T) {
                dp[i][timeAfterEat] = (dp[i][timeAfterEat] > dp[i - 1][timeAfterEat - time] + value) ? 
                                      dp[i][timeAfterEat] : 
                                      (dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Find the maximum value that can be obtained after eating all the activities
    int max_value = 0;
    for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
        if (dp[N][timeAfterEat] > max_value) {
            max_value = dp[N][timeAfterEat];
        }
    }

    // Print the maximum value
    printf("%d\n", max_value);

    // Free allocated memory
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
    free(AB);

    return 0;
}

// <END-OF-CODE>
