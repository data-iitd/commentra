#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long mod = 1000000007; // Define the modulo constant
    int n, k; // Declare the integer variables n and k
    scanf("%d %d", &n, &k); // Read the integer n and k from input

    int l = 1; // Initialize the starting point of the segment
    int q = 0; // Initialize the size of the len array
    int *len = (int *) malloc(sizeof(int) * (n + 1)); // Create an array to store segment lengths
    while (l <= n) {
        int r = n / (n / l); // Calculate the ending point of the segment
        len[q++] = r - l + 1; // Add the length of the segment to the array
        l = r + 1; // Move to the next segment
    }

    long *dp = (long *) malloc(sizeof(long) * (k * (q + 1))); // Initialize the dp array with sufficient size

    // Calculate the prefix sums of the lengths and store them in the dp array
    for (int j = 1; j <= q; j++) {
        dp[j] = len[j - 1] + dp[j - 1];
    }

    // Main loop to calculate the dynamic programming values for k iterations
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1];
            dp[i * (q + 1) + j] %= mod; // Ensure the value does not exceed the modulo
        }
    }

    // Print the result stored in the dp array
    printf("%ld\n", dp[k * (q + 1) - 1]);
    free(len); // Free the memory allocated for the len array
    free(dp); // Free the memory allocated for the dp array
    return 0;
}

