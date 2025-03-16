#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    long long mod = 1e9 + 7; // Define the modulo constant
    int n, k;
    scanf("%d %d", &n, &k); // Read the integers n and k from input

    int len[100000]; // Array to store segment lengths
    int l = 1; // Initialize the starting point of the segment
    int index = 0; // Index for the len array
    while (l <= n) {
        int r = n / (n / l); // Calculate the ending point of the segment
        len[index++] = r - l + 1; // Store the length of the segment
        l = r + 1; // Move to the next segment
    }

    int q = index; // Store the size of the len array in q
    long long dp[k + 1][q + 1]; // Initialize the dp array with sufficient size

    // Calculate the prefix sums of the lengths and store them in the dp array
    for (int j = 1; j <= q; j++) {
        dp[0][j] = dp[0][j - 1] + len[j - 1];
    }

    // Main loop to calculate the dynamic programming values for k iterations
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][q - j + 1] * len[j - 1];
            dp[i][j] %= mod; // Ensure the value does not exceed the modulo
        }
    }

    // Print the result stored in the dp array
    printf("%lld\n", dp[k - 1][q]);

    return 0;
}
