#include <stdio.h>
#include <stdlib.h>

#define TIME 0
#define VAL 1

// Structure to hold time and value of each item
typedef struct {
    int time;
    int value;
} Item;

// Comparison function for sorting items based on value
int compare(const void *a, const void *b) {
    return ((Item *)a)->value - ((Item *)b)->value;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    // Initializing data structures
    Item *time_value = malloc((N + 1) * sizeof(Item));
    time_value[0] = (Item){-1, -1}; // Placeholder at index 0

    // Reading item details
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i].time, &time_value[i].value);
    }

    // Sorting items based on their value
    qsort(time_value + 1, N, sizeof(Item), compare);

    // Dynamic programming table initialization
    int **dp = malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = malloc(T * sizeof(int));
    }

    // Base cases for DP table
    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }

    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
        for (int t = 1; t < T; t++) {
            if (time_value[n].time > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                dp[n][t] = dp[n - 1][t] > (time_value[n].value + dp[n - 1][t - time_value[n].time]) ? 
                           dp[n - 1][t] : 
                           (time_value[n].value + dp[n - 1][t - time_value[n].time]);
            }
        }
    }

    // Calculating maximum value
    int val_acum = time_value[N].value;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n].value;
        t -= time_value[n + 1].time;
        if (t < 0) {
            break;
        } else {
            max_val = max_val > (val_acum + dp[n - 1][t]) ? max_val : (val_acum + dp[n - 1][t]);
        }
    }

    // Printing result
    printf("%d\n", max_val);

    // Free allocated memory
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
    free(time_value);

    return 0;
}

// Helper function to find maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// <END-OF-CODE>
