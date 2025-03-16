#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Constants to represent indices for time and value
#define TIME 0
#define VAL 1

// Function to read input from standard input
int read_input(int *N, int *T, int *time_value) {
    // Read the number of items (N) and the maximum time (T)
    scanf("%d %d", N, T);

    // Initialize a list to store time and value pairs, starting with a dummy entry
    time_value[0] = -1;
    for (int i = 1; i <= *N; i++) {
        scanf("%d %d", &time_value[i * 2 - 1], &time_value[i * 2]);
    }

    return 0;
}

// Function to sort the time_value list based on the value (VAL)
void sort_time_value(int *N, int *time_value) {
    // Sort the time_value list based on the value (VAL)
    for (int i = 1; i <= *N; i++) {
        for (int j = i; j > 0; j--) {
            if (time_value[j * 2] > time_value[(j - 1) * 2]) {
                int temp = time_value[j * 2];
                time_value[j * 2] = time_value[(j - 1) * 2];
                time_value[(j - 1) * 2] = temp;

                temp = time_value[j * 2 - 1];
                time_value[j * 2 - 1] = time_value[(j - 1) * 2 - 1];
                time_value[(j - 1) * 2 - 1] = temp;
            }
        }
    }
}

// Function to initialize a 2D list for dynamic programming, with -1 as default values
int **init_dp(int *N, int *T) {
    int **dp = (int **) malloc(((*N) + 1) * sizeof(int *));
    for (int i = 0; i <= *N; i++) {
        dp[i] = (int *) malloc((*T + 1) * sizeof(int));
        for (int j = 0; j <= *T; j++) {
            dp[i][j] = -1;
        }
    }

    return dp;
}

// Function to free the 2D list for dynamic programming
void free_dp(int **dp, int *N) {
    for (int i = 0; i <= *N; i++) {
        free(dp[i]);
    }
    free(dp);
}

// Function to initialize the dynamic programming table
int fill_dp(int *N, int *T, int *time_value, int **dp) {
    // Base case: If time is 0, the maximum value is 0 for all items
    for (int t = 0; t <= *T; t++) {
        dp[0][t] = 0;
    }

    // Fill the dynamic programming table
    for (int n = 1; n <= *N; n++) {
        // Base case: If no time is available, the maximum value is 0
        dp[n][0] = 0;
        for (int t = 1; t <= *T; t++) {
            // If the current item's time exceeds the available time, skip the item
            if (time_value[n * 2] > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                // Choose the maximum between not taking the item and taking it
                dp[n][t] = max(dp[n - 1][t], time_value[n * 2 + 1] + dp[n - 1][t - time_value[n * 2]]);
            }
        }
    }

    return 0;
}

// Function to backtrack to find the maximum value considering previous items
int backtrack(int *N, int *T, int *time_value, int **dp, int *val_acum, int *t, int *max_val) {
    // Initialize the maximum value with the last item's value
    *val_acum = time_value[(*N) * 2 + 1];
    *t = *T - 1;
    *max_val = *val_acum + dp[(*N) - 1][*t];

    // Backtrack to find the maximum value considering previous items
    for (int n = (*N) - 1; n > 0; n--) {
        *val_acum += time_value[n * 2 + 1];
        *t -= time_value[(n + 1) * 2];

        // If time goes negative, break the loop
        if (*t < 0) {
            break;
        } else {
            // Update the maximum value if a better option is found
            *max_val = max(*max_val, *val_acum + dp[n - 1][*t]);
        }
    }

    return 0;
}

// Main function
int main() {
    // Read the number of items (N) and the maximum time (T)
    int N, T;
    read_input(&N, &T, (int *) malloc((N + 1) * 2 * sizeof(int)));

    // Initialize a list to store time and value pairs, starting with a dummy entry
    int *time_value = (int *) malloc((N + 1) * 2 * sizeof(int));
    time_value[0] = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i * 2 - 1], &time_value[i * 2]);
    }

    // Sort the time_value list based on the value (VAL)
    sort_time_value(&N, time_value);

    // Initialize a 2D list for dynamic programming, with -1 as default values
    int **dp = init_dp(&N, &T);

    // Fill the dynamic programming table
    fill_dp(&N, &T, time_value, dp);

    // Initialize the maximum value with the last item's value
    int val_acum, t, max_val;
    backtrack(&N, &T, time_value, dp, &val_acum, &t, &max_val);

    // Print the maximum value achievable within the given time
    printf("%d\n", max_val);

    // Free the 2D list for dynamic programming
    free_dp(dp, &N);

    // Free the time_value list
    free(time_value);

    return 0;
}

