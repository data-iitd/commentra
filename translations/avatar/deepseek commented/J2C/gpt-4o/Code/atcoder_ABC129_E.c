#include <stdio.h> // Including standard input-output library

#define M 1000000007 // Defining a constant for modulo operation

int main() {
    char s[100001]; // Array to hold the input string (max length 100000)
    scanf("%s", s); // Reading the input string
    int n = 0; // Variable to hold the length of the input string

    // Calculating the length of the input string
    while (s[n] != '\0') {
        n++;
    }

    int dp[n + 1][2]; // Initializing the dynamic programming table
    dp[0][0] = 1; // Setting the base case for dp[0][0]
    dp[0][1] = 0; // Initializing dp[0][1] to 0

    // Iterating through each character of the input string
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0]; // Copying the previous state for '0'
            dp[i + 1][1] = dp[i][1]; // Copying the previous state for '0'
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M; // Updating dp[i+1][1] for '1'
        }

        // Additional updates for '0' and '1'
        if (s[i] == '0') {
            dp[i + 1][1] += (dp[i][1] * 2) % M; // Updating dp[i+1][1] for '0'
            dp[i + 1][1] %= M; // Ensuring the value stays within the modulo range
        } else {
            dp[i + 1][0] += (dp[i][0] * 2) % M; // Updating dp[i+1][0] for '1'
            dp[i + 1][1] += (dp[i][1] * 2) % M; // Updating dp[i+1][1] for '1'
            dp[i + 1][0] %= M; // Ensuring the value stays within the modulo range
            dp[i + 1][1] %= M; // Ensuring the value stays within the modulo range
        }
    }

    // Printing the result as the sum of dp[n][0] and dp[n][1] modulo M
    printf("%d\n", (dp[n][0] + dp[n][1]) % M);
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
