#include <stdio.h>
#include <string.h>

#define M 1000000007

int main() {
    // Read a line of input
    char s[100001]; // Assuming the maximum length of the input string is 100000
    fgets(s, sizeof(s), stdin);
    
    // Get the length of the input character array
    int n = strlen(s) - 1; // Subtract 1 to ignore the newline character
    
    // Initialize a 2D array for dynamic programming
    // dp[i][0] will store the count of valid sequences ending with '0'
    // dp[i][1] will store the count of valid sequences ending with '1'
    long long dp[n + 1][2];
    
    // Base case: There is one way to have an empty sequence
    dp[0][0] = 1;
    dp[0][1] = 0; // Initialize the count for sequences ending with '1' to 0
    
    // Iterate through each character in the input string
    for (int i = 0; i < n; i++) {
        // If the current character is '0'
        if (s[i] == '0') {
            // Carry forward the counts for sequences ending with '0' and '1'
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            
            // Count sequences ending with '1' that can be formed by doubling the previous count
            dp[i + 1][1] += (dp[i][1] * 2) % M;
            dp[i + 1][1] %= M;
        } else {
            // If the current character is '1', calculate new counts
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M;
            
            // Count sequences ending with '0' that can be formed by doubling the previous count
            dp[i + 1][0] += (dp[i][0] * 2) % M;
            // Count sequences ending with '1' that can be formed by doubling the previous count
            dp[i + 1][1] += (dp[i][1] * 2) % M;
            
            // Ensure the counts remain within the modulo limit
            dp[i + 1][0] %= M;
            dp[i + 1][1] %= M;
        }
    }
    
    // Output the total number of valid sequences
    printf("%lld\n", (dp[n][0] + dp[n][1]) % M);
    
    return 0;
}

// <END-OF-CODE>
