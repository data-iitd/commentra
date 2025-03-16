#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

void run(void) {
    char cs[100001];
    int dp[100001][13];
    int base = 1;
    int i, j, k, next, pre;

    // Read the input string
    scanf("%s", cs);

    // Initialize the dp array
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // There's one way to form a number divisible by 13 with an empty string

    // Iterate through the characters of the input from the last to the first
    for (i = 0; i < strlen(cs); ++i) {
        // Check if the current character is a '?', which can be any digit
        if (cs[strlen(cs) - 1 - i] == '?') {
            // Loop through all possible previous remainders
            for (pre = 0; pre < 13; ++pre) {
                // Loop through all possible next digits (0-9)
                for (next = 0; next < 10; ++next) {
                    // Update the dp array for the current position and remainder
                    dp[i + 1][(base * next + pre) % 13] += dp[i][pre];
                    dp[i + 1][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            // If the character is a digit, convert it to an integer
            next = cs[strlen(cs) - 1 - i] - '0';
            // Loop through all possible previous remainders
            for (pre = 0; pre < 13; ++pre) {
                // Update the dp array for the current position and remainder
                dp[i + 1][(base * next + pre) % 13] += dp[i][pre];
                dp[i + 1][(base * next + pre) % 13] %= MOD;
            }
        }
        // Update the base value for the next iteration (moving to the next digit)
        base = base * 10 % 13;
    }

    // Output the result, which is the number of ways to form a number divisible by 13
    printf("%d\n", dp[strlen(cs)][5]);
}

int main(void) {
    run();
    return 0;
}
