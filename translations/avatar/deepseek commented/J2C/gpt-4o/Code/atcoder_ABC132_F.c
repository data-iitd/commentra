#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Read the integers n and k from input

    // Create an array to store segment lengths
    int *len = (int *)malloc(n * sizeof(int));
    int l = 1, q = 0;

    // Calculate segment lengths
    while (l <= n) {
        int r = n / (n / l); // Calculate the ending point of the segment
        len[q++] = r - l + 1; // Add the length of the segment to the array
        l = r + 1; // Move to the next segment
    }

    long *dp = (long *)malloc(k * (q + 1) * sizeof(long)); // Initialize the dp array

    // Calculate the prefix sums of the lengths and store them in the dp array
    for (int j = 1; j <= q; j++) {
        dp[j] = len[j - 1] + dp[j - 1];
    }

    // Main loop to calculate the dynamic programming values for k iterations
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = (dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1]) % MOD;
        }
    }

    // Print the result stored in the dp array
    printf("%ld\n", dp[k * (q + 1) - 1]);

    // Free allocated memory
    free(len);
    free(dp);

    return 0;
}

// <END-OF-CODE>
