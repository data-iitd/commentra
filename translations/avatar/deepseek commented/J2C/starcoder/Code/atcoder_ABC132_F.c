#include <stdio.h>
#include <stdlib.h>

int main() {
    long mod = (long) 1e9 + 7; // Define the modulo constant
    int n, k;
    scanf("%d %d", &n, &k); // Read the integer n and k from input
    int l = 1; // Initialize the starting point of the segment
    int q = 0; // Initialize the size of the len array
    int *len = (int *) malloc(sizeof(int) * (n + 1)); // Allocate memory for the len array
    while (l <= n) {
        int r = n / (n / l); // Calculate the ending point of the segment
        len[q] = r - l + 1; // Add the length of the segment to the len array
        q++; // Increment the size of the len array
        l = r + 1; // Move to the next segment
    }

    long *dp = (long *) malloc(sizeof(long) * (k * (q + 1))); // Allocate memory for the dp array
    for (int j = 1; j <= q; j++) {
        dp[j] = len[j - 1] + dp[j - 1]; // Calculate the prefix sums of the lengths
    }

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1];
            dp[i * (q + 1) + j] %= mod; // Ensure the value does not exceed the modulo
        }
    }

    printf("%ld\n", dp[k * (q + 1) - 1]); // Print the result stored in the dp array
    return 0;
}

