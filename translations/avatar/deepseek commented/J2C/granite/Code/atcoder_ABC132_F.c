
#include <stdio.h> // Include the standard input/output library
#define mod 100000007 // Define the modulo constant

int main() {
    int n, k, q, l, r, i, j; // Declare and initialize the required variables
    long dp[100001]; // Declare the dp array with sufficient size

    scanf("%d%d", &n, &k); // Read the integer n and k from input
    q = 0; // Initialize the size of the len ArrayList in q
    l = 1; // Initialize the starting point of the segment
    while (l <= n) {
        r = n / (n / l); // Calculate the ending point of the segment
        q++; // Increment the size of the len ArrayList in q
        l = r + 1; // Move to the next segment
    }

    dp[0] = 0; // Initialize the dp array with the base case
    for (i = 1; i <= q; i++) {
        dp[i] = dp[i - 1] + n / (n / i); // Calculate the prefix sums of the lengths and store them in the dp array
    }

    for (i = 1; i < k; i++) {
        for (j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = (dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * (n / (n / j))) % mod; // Calculate the dynamic programming values for k iterations
        }
    }

    printf("%ld\n", dp[k * (q + 1) - 1]); // Print the result stored in the dp array
    return 0; // Return 0 to indicate successful execution
}

