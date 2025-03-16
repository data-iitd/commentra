#include <stdio.h>
#include <stdlib.h>

// Define the modulus value for calculations to prevent overflow
#define mod 1000000007

int main() {
    // Read input values for n and k
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a list to store coefficients
    int *coef = (int *)malloc(sizeof(int) * n);

    // Calculate coefficients based on the divisors of n
    for (int i = 1; i <= n; i++) {
        // Append the count of divisors in the range
        coef[i - 1] = (n / i) - (n / (i + 1));
    }

    // Fill the remaining coefficients with 1s to ensure the length matches n
    for (int i = n; i > 0; i--) {
        if (coef[i - 1] == 0) {
            coef[i - 1] = 1;
        }
    }

    // Reverse the coefficients list for further processing
    for (int i = 0; i < n / 2; i++) {
        int tmp = coef[i];
        coef[i] = coef[n - i - 1];
        coef[n - i - 1] = tmp;
    }

    // Get the length of the coefficients list
    int nn = n;

    // Initialize a 2D list for dynamic programming
    // dp[i][j] will store the result for i selections and j coefficients
    int **dp = (int **)malloc(sizeof(int *) * (k + 1));
    for (int i = 0; i < k + 1; i++) {
        dp[i] = (int *)malloc(sizeof(int) * nn);
    }

    // Base case: there's one way to select 0 items (select nothing)
    dp[0][0] = 1;

    // Fill the dp table for k selections
    for (int i = 1; i <= k; i++) {
        int tmp = 0;  // Temporary variable to accumulate values
        // Iterate through the coefficients in reverse order
        for (int j = nn - 1; j >= 0; j--) {
            // Accumulate the number of ways to select items
            tmp += dp[i - 1][j];
            tmp %= mod;  // Ensure the value stays within modulus
            // Calculate the number of ways to select i items using the j-th coefficient
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;  // Again, ensure the value stays within modulus
    }

    // Output the total number of ways to select k items, taking modulus
    printf("%d", dp[k][0]);

    // Free the memory
    free(coef);
    for (int i = 0; i < k + 1; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}

