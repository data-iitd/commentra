A: Sure, here is the equivalent C code for the provided Go program:

#include <stdio.h>
#include <math.h>

// max function returns the maximum of two integers.
int max(int lhs, int rhs) {
    return lhs > rhs ? lhs : rhs;
}

int main() {
    // Declare variables for the number of items (N) and the maximum weight (M).
    int N, M;

    // Read the number of items and the maximum weight from standard input.
    scanf("%d %d", &N, &M);

    // Initialize arrays to hold the weights and values of the items.
    int values[N];
    int weights[N];

    // Read the weights and values of each item from standard input.
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Initialize a 2D array for dynamic programming table.
    int dp[N+1][M+1];

    // Fill the dynamic programming table.
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Output the maximum value that can be obtained with the given weight limit.
    printf("%d\n", dp[N][M]);

    return 0;
}
