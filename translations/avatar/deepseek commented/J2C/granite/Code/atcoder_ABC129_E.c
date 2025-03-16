
#include <stdio.h> // Include the standard input/output library
#define M 1000000007 // Define a constant for modulo operation

int main() {
    char s[1000001]; // Declare a char array to store the input string
    int n, i; // Declare variables for the length of the input string and loop control
    int dp[1000001][2] = {{1, 0}}; // Initialize the dynamic programming table

    // Read the input string and calculate its length
    fgets(s, 1000001, stdin);
    n = strlen(s) - 1;

    // Iterate through each character of the input string
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0]; // Copy the previous state for '0'
            dp[i + 1][1] = dp[i][1]; // Copy the previous state for '0'
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M; // Update dp[i+1][1] for '1'
        }

        // Additional updates for '0' and '1'
        if (s[i] == '0') {
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % M) % M; // Update dp[i+1][1] for '0'
        } else {
            dp[i + 1][0] = (dp[i + 1][0] + (dp[i][0] * 2) % M) % M; // Update dp[i+1][0] for '1'
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % M) % M; // Update dp[i+1][1] for '1'
        }
    }

    // Print the result as the sum of dp[n][0] and dp[n][1] modulo M
    printf("%d\n", (dp[n][0] + dp[n][1]) % M);

    return 0; // Return 0 to indicate successful execution
}
