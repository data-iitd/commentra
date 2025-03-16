#include <stdio.h>
#include <string.h> // For memset
#include <limits.h> // For LONG_MIN

#define MAX_SIZE 1150

int main() {
    int v1, v2, t, d; // Declare input variables
    scanf("%d %d %d %d", &v1, &v2, &t, &d); // Read input variables

    long dp[t - 1][MAX_SIZE]; // Create a 2D array for dynamic programming

    // Initialize the dp table
    for (int i = 0; i < t - 1; i++) {
        memset(dp[i], LONG_MIN, sizeof(dp[i])); // Initialize all elements to LONG_MIN
        dp[i][v1] = v1; // Set the value of the cell (i, v1) to v1
    }

    long sum = 0; // Initialize sum to 0

    // Fill the dp table using dynamic programming
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX_SIZE) {
                    dp[i][j] = (dp[i][j] > dp[i - 1][j + x] + j) ? dp[i][j] : (dp[i - 1][j + x] + j); // Update dp[i][j]
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = (dp[i][j] > dp[i - 1][j - x] + j) ? dp[i][j] : (dp[i - 1][j - x] + j); // Update dp[i][j]
                }
            }
        }
        sum += dp[i][MAX_SIZE - 1]; // Add the value of the last cell of the current row to sum
    }

    long ans = LONG_MIN; // Initialize ans with LONG_MIN

    // Find the maximum value that can be obtained
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (abs(j - v2) <= d) { // Check the absolute difference
                ans = (ans > dp[i][j] + v2) ? ans : (dp[i][j] + v2); // Update ans
            }
        }
    }

    printf("%ld\n", ans); // Print the final answer
    return 0; // Return success
}

// <END-OF-CODE>
