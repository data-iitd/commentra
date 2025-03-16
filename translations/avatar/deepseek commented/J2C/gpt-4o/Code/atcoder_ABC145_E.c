#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T); // Read the number of dishes and the time limit

    // Initialize the array to store dishes with their time and value
    int **AB = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        AB[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &AB[i][0], &AB[i][1]); // Read the time and value for each dish
    }

    // Sort the dishes based on their eating time
    qsort(AB, N, sizeof(int *), compare);

    // Initialize the DP table with dimensions (N+1) x 6001
    int dp[N + 1][6001] = {0};

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Inherit the maximum value from the previous dish
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            // Get the time and value of the current dish
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];

            // If the dish can be eaten after the given time, update the DP table
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = (dp[i][timeAfterEat] > dp[i - 1][timeAfterEat - time] + value) ? 
                                      dp[i][timeAfterEat] : 
                                      (dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Find the maximum value that can be obtained within the time limit
    int max_value = 0;
    for (int j = 0; j <= 6000; j++) {
        if (dp[N][j] > max_value) {
            max_value = dp[N][j];
        }
    }
    printf("%d\n", max_value);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(AB[i]);
    }
    free(AB);

    return 0;
}

// <END-OF-CODE>
