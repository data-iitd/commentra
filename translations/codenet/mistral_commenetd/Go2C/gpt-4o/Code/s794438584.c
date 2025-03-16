#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int lhs, int rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

int main() {
    // Initialize variables N and M to read input
    int N, M;
    // Read input values of N and M from standard input
    scanf("%d %d", &N, &M);
    
    // Initialize arrays values and weights of size N to read input
    int *values = (int *)malloc(N * sizeof(int));
    int *weights = (int *)malloc(N * sizeof(int));
    
    // Read input values and weights for each index i from 0 to N-1
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    
    // Initialize 2D array dp of size (N+1) x (M+1)
    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int *)malloc((M + 1) * sizeof(int));
    }
    
    // Iterate through each index i from 1 to N and each index j from 0 to M
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // Initialize dp[i][j] with dp[i-1][j]
            dp[i][j] = dp[i - 1][j];
            // If j is greater than or equal to the weight of the current index i-1,
            // update dp[i][j] with the maximum value between dp[i][j] and dp[i-1][j-weights[i-1]]+values[i-1]
            if (j >= weights[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    
    // Print the final value of dp[N][M]
    printf("%d\n", dp[N][M]);
    
    // Free allocated memory
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
    free(values);
    free(weights);
    
    return 0;
}

// <END-OF-CODE>
