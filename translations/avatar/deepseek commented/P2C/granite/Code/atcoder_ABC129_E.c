
#include <stdio.h>
#define MOD 100000007  // Set the modulus to a large prime number

int main() {
    char l[100001];  // Declare a character array to store the input string
    int n;  // Declare an integer to store the length of the input string
    scanf("%s", l);  // Read the input string
    n = strlen(l);  // Calculate the length of the input string

    // Initialize the dynamic programming table
    int dp[n + 1][2] = {{1, 0}};  // Initialize the first row with one empty sequence

    // Iterate over each character in the input string
    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            dp[i + 1][0] = (dp[i][0] + dp[i][1] * 3) % MOD;  // Add sequences ending with zero
            dp[i + 1][1] = dp[i][1];  // Copy sequences ending with one
        } else {
            dp[i + 1][0] = (dp[i][0] * 2 + dp[i][1] * 3) % MOD;  // Double sequences ending with zero
            dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % MOD;  // Add sequences ending with zero
        }
    }

    // Calculate and print the final result
    int result = (dp[n][0] + dp[n][1]) % MOD;
    printf("%d\n", result);

    return 0;
}
