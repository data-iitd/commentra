#include <stdio.h>

#define MOD 1000000007

int main() {
    // Read the input string
    char l[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", l);

    // Get the length of the input string
    int n = 0;
    while (l[n] != '\0') n++;

    // Initialize a 2D array (dp) to store the number of ways to form valid sequences
    long long dp[n + 1][2];
    
    // Base case: there's one way to have an empty sequence
    dp[0][0] = 1;
    dp[0][1] = 0;

    // Iterate through each character in the input string
    for (int i = 0; i < n; i++) {
        char c = l[i];
        if (c == '0') {
            // If the current character is '0', update the counts for sequences ending with '0'
            dp[i + 1][0] = dp[i][0]; // Continue sequences ending with '0'
            // Update counts for sequences ending with '1' (can be formed by adding '0' to previous '1' sequences)
            dp[i + 1][1] = (dp[i][1] * 3) % MOD; // Three ways to extend previous '1' sequences
        } else {
            // If the current character is '1', update the counts for sequences ending with '0'
            dp[i + 1][0] = (dp[i][0] * 2) % MOD; // Two ways to extend previous '0' sequences
            // Update counts for sequences ending with '1'
            dp[i + 1][1] = (dp[i][0] + (dp[i][1] * 3) % MOD) % MOD; // One way to form a new '1' from previous '0' and three ways to extend previous '1' sequences
        }
    }

    // Calculate the total number of valid sequences by summing both counts for the last character
    // and apply modulus again
    long long result = (dp[n][0] + dp[n][1]) % MOD;
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
