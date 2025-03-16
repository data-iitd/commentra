#include <stdio.h>
#include <string.h>

#define MOD 1000000007

void run() {
    // Initialize a character array to read input
    char cs[100]; // Assuming the maximum length of the input string is 100
    scanf("%s", cs);
    
    // Get the length of the input string
    int len = strlen(cs);
    
    // Initialize a 2D array for dynamic programming to store results
    long dp[100][13] = {0}; // Assuming the maximum length of the input string is 100
    
    // Variable to keep track of the base value for calculations
    int base = 1;
    
    // Iterate through the characters of the input from the last to the first
    for (int i = 0; i < len; ++i) {
        // Check if the current character is a '?', which can be any digit
        if (cs[len - 1 - i] == '?') {
            // Loop through all possible previous remainders
            for (int pre = 0; pre < 13; ++pre) {
                // Loop through all possible next digits (0-9)
                for (int next = 0; next < 10; ++next) {
                    // Update the dp array for the current position and remainder
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    // Ensure the result stays within the MOD limit
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            // If the character is a digit, convert it to an integer
            int next = cs[len - 1 - i] - '0';
            // Loop through all possible previous remainders
            for (int pre = 0; pre < 13; ++pre) {
                // Update the dp array for the current position and remainder
                dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                // Ensure the result stays within the MOD limit
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        // Update the base value for the next iteration (moving to the next digit)
        base = base * 10 % 13;
    }
    
    // Output the result, which is the number of ways to form a number divisible by 13
    printf("%ld\n", dp[len - 1][5]);
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
