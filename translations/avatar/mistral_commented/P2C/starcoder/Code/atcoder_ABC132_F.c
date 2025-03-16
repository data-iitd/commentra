
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the modulus value
    int mod = 1000000007;

    // Read input values for n and k
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a list 'coef' to store coefficients
    int *coef = (int *)malloc(sizeof(int) * n);

    // Calculate coefficients for n up to its square root
    for (int i = 1; i <= (int)sqrt(n); i++) {
        // Calculate the difference between the quotient and the next quotient
        coef[i - 1] = n / i - n / (i + 1);
    }

    // Add remaining coefficients to the list
    for (int i = (int)sqrt(n); i < n; i++) {
        coef[i] = 1;
    }

    // Reverse the list 'coef'
    for (int i = 0; i < n / 2; i++) {
        int tmp = coef[i];
        coef[i] = coef[n - i - 1];
        coef[n - i - 1] = tmp;
    }

    // Initialize a 2D list 'dp' to store intermediate results
    int **dp = (int **)malloc(sizeof(int *) * (k + 1));
    for (int i = 0; i <= k; i++) {
        dp[i] = (int *)malloc(sizeof(int) * n);
    }

    // Initialize the first row of dp with 1 at index 0
    dp[0][0] = 1;

    // Calculate dp[i][j] for i from 1 to k and j from n-1 to 0
    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        // Iterate through the reverse list 'coef' from j = n-1 to j = 0
        for (int j = n - 1; j >= 0; j--) {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp += dp[i - 1][j];
            tmp = (tmp + coef[j]) % mod;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }

    // Calculate the final answer by summing up dp[k]
    printf("%d", dp[k][0]);

    // Free the memory
    free(coef);
    for (int i = 0; i <= k; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}

