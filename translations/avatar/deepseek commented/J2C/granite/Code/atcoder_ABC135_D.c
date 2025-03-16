
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// MOD constant with value 10^9 + 7
#define MOD 100000007

// Main logic of the program
int main() {
    char s[100001];
    scanf("%s", s);

    // 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
    long long dp[100001][13];

    // Initialize the base variable to represent the current power of 10
    int base = 1;

    // Loop through the character array from the least significant digit to the most significant digit
    for (int i = 0; i < strlen(s); ++i) {
        if (s[strlen(s) - 1 - i] == '?') {
            // If the current character is '?', we iterate through all possible digits (0-9)
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i + 1][(base * next + pre) % 13] += dp[i][pre];
                    dp[i + 1][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            // If the current character is not '?', we update the dp array based on the actual digit
            int next = s[strlen(s) - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i + 1][(base * next + pre) % 13] += dp[i][pre];
                dp[i + 1][(base * next + pre) % 13] %= MOD;
            }
        }
        // Update the base variable to the next power of 10 modulo 13
        base = base * 10 % 13;
    }

    // Print the number of ways to achieve the remainder 5 when the number is divided by 13
    printf("%lld\n", dp[strlen(s)][5]);

    return 0;
}
// END-OF-CODE