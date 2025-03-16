#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    // Read input values for n and k
    long long n, k;
    scanf("%lld %lld", &n, &k);

    // Initialize an array 'coef' to store coefficients
    long long *coef = (long long *)malloc((n + 1) * sizeof(long long));
    int nn = 0;

    // Calculate coefficients for n up to its square root
    for (long long i = 1; i * i <= n; i++) {
        coef[nn++] = n / i - n / (i + 1);
    }

    // Add remaining coefficients to the list
    for (long long i = 0; i < n - (n / (nn ? nn : 1)); i++) {
        coef[nn++] = 1;
    }

    // Reverse the list 'coef'
    for (int i = 0; i < nn / 2; i++) {
        long long temp = coef[i];
        coef[i] = coef[nn - 1 - i];
        coef[nn - 1 - i] = temp;
    }

    // Initialize a 2D array 'dp' to store intermediate results
    long long **dp = (long long **)malloc((k + 1) * sizeof(long long *));
    for (long long i = 0; i <= k; i++) {
        dp[i] = (long long *)malloc(nn * sizeof(long long));
    }

    // Initialize the first row of dp with 1 at index 0
    dp[0][0] = 1;

    // Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
    for (long long i = 1; i <= k; i++) {
        long long tmp = 0;
        // Iterate through the reverse list 'coef' from j = nn-1 to j = 0
        for (int j = nn - 1; j >= 0; j--) {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp = (tmp + dp[i - 1][j]) % MOD;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = (coef[j] * tmp) % MOD;
        }
    }

    // Calculate the final answer by summing up dp[k]
    long long result = 0;
    for (int j = 0; j < nn; j++) {
        result = (result + dp[k][j]) % MOD;
    }

    // Print the result
    printf("%lld\n", result);

    // Free allocated memory
    for (long long i = 0; i <= k; i++) {
        free(dp[i]);
    }
    free(dp);
    free(coef);

    return 0;
}

// <END-OF-CODE>
