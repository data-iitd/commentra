#include <stdio.h>
#include <stdlib.h>

// max function returns the maximum of two integers.
int max(int lhs, int rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

int main() {
    // Declare variables for the number of items (N) and the maximum weight (M).
    int N, M;

    // Read the number of items and the maximum weight from standard input.
    scanf("%d %d", &N, &M);

    // Initialize arrays to hold the weights and values of the items.
    int *values = (int *)malloc(N * sizeof(int));
    int *weights = (int *)malloc(N * sizeof(int));

    // Read the weights and values of each item from standard input.
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Initialize a 2D array for dynamic programming table.
    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int *)malloc((M + 1) * sizeof(int));
    }

    // Fill the dynamic programming table.
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // If the current item is not included, carry forward the previous value.
            dp[i][j] = dp[i - 1][j];

            // If the current item's weight is less than or equal to the current capacity.
            if (j >= weights[i - 1]) {
                // Calculate the maximum value by including the current item.
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    // Output the maximum value that can be obtained with the given weight limit.
    printf("%d\n", dp[N][M]);

    // Free allocated memory
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
    free(weights);
    free(values);

    return 0;
}

// <END-OF-CODE>
