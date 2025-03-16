#include <stdio.h>
#include <stdlib.h>

// Function to return the maximum of two integers
int max(int lhs, int rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

int main() {
    int N, M; // N: number of items, M: maximum weight capacity
    scanf("%d %d", &N, &M); // Read the number of items and maximum weight capacity

    int *values = (int *)malloc(N * sizeof(int)); // Array to store values of items
    int *weights = (int *)malloc(N * sizeof(int)); // Array to store weights of items

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weights[i], &values[i]); // Read the weight and value of each item
    }

    // Initialize the DP table
    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i < N + 1; i++) {
        dp[i] = (int *)malloc((M + 1) * sizeof(int));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i - 1][j]; // Inherit the maximum value from the previous item
            if (j >= weights[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]); // Update the DP table with the current item
            }
        }
    }

    printf("%d\n", dp[N][M]); // Print the maximum value that can be achieved

    // Free allocated memory
    for (int i = 0; i < N + 1; i++) {
        free(dp[i]);
    }
    free(dp);
    free(values);
    free(weights);

    return 0;
}

// <END-OF-CODE>
