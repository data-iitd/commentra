#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Reading the first two integer inputs

    int *len = (int *)malloc(n * sizeof(int)); // Dynamic array to store lengths of subsequences
    int l = 1, q = 0;

    while (l <= n) { // Loop to calculate lengths of subsequences
        int r = n / (n / l);
        len[q++] = r - l + 1; // Store the length of the current subsequence
        l = r + 1; // Move to the next subsequence
    }

    long *dp = (long *)malloc(k * (q + 1) * sizeof(long)); // Dynamic array for dp results

    for (int j = 1; j <= q; j++) { // Fill the first row of dp
        dp[j] = len[j - 1] + dp[j - 1];
    }

    for (int i = 1; i < k; i++) { // Nested loop for overlapping subsequences
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1];
            dp[i * (q + 1) + j] %= MOD; // Modulo operation
        }
    }

    printf("%ld\n", dp[k * (q + 1) - 1]); // Print the final result

    free(len); // Free allocated memory
    free(dp); // Free allocated memory

    return 0;
}

// <END-OF-CODE>
