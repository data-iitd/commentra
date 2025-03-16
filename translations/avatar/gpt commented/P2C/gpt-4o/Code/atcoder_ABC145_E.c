#include <stdio.h>
#include <stdlib.h>

#define TIME 0
#define VAL 1

// Structure to hold time and value pairs
typedef struct {
    int time;
    int value;
} TimeValue;

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return ((TimeValue *)a)->value - ((TimeValue *)b)->value;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    // Allocate memory for time and value pairs
    TimeValue *time_value = malloc((N + 1) * sizeof(TimeValue));
    time_value[0] = (TimeValue){-1, -1}; // Dummy entry

    // Read the time and value pairs
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i].time, &time_value[i].value);
    }

    // Sort the time_value array based on the value
    qsort(time_value, N + 1, sizeof(TimeValue), compare);

    // Initialize a 2D array for dynamic programming
    int **dp = malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = malloc(T * sizeof(int));
        for (int j = 0; j < T; j++) {
            dp[i][j] = -1; // Default values
        }
    }

    // Base case: If time is 0, the maximum value is 0 for all items
    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }

    // Fill the dynamic programming table
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0; // Base case: If no time is available, the maximum value is 0
        for (int t = 1; t < T; t++) {
            if (time_value[n].time > t) {
                dp[n][t] = dp[n - 1][t]; // Skip the item
            } else {
                // Choose the maximum between not taking the item and taking it
                dp[n][t] = (dp[n - 1][t] > time_value[n].value + dp[n - 1][t - time_value[n].time]) ?
                            dp[n - 1][t] : (time_value[n].value + dp[n - 1][t - time_value[n].time]);
            }
        }
    }

    // Initialize the maximum value with the last item's value
    int val_acum = time_value[N].value;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    // Backtrack to find the maximum value considering previous items
    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n].value;
        t -= time_value[n + 1].time;

        // If time goes negative, break the loop
        if (t < 0) {
            break;
        } else {
            // Update the maximum value if a better option is found
            max_val = (max_val > val_acum + dp[n - 1][t]) ? max_val : (val_acum + dp[n - 1][t]);
        }
    }

    // Print the maximum value achievable within the given time
    printf("%d\n", max_val);

    // Free allocated memory
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
    free(time_value);

    return 0;
}

// <END-OF-CODE>
