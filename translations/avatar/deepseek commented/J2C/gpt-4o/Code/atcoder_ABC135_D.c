#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_LENGTH 100

void run() {
    char cs[MAX_LENGTH];
    scanf("%s", cs);
    int length = strlen(cs);
    
    // 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
    long dp[MAX_LENGTH][13] = {0};

    // Initialize the base variable to represent the current power of 10
    int base = 1;

    // Loop through the character array from the least significant digit to the most significant digit
    for (int i = 0; i < length; ++i) {
        if (cs[length - 1 - i] == '?') {
            // If the current character is '?', we iterate through all possible digits (0-9)
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            // If the current character is not '?', we update the dp array based on the actual digit
            int next = cs[length - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        // Update the base variable to the next power of 10 modulo 13
        base = base * 10 % 13;
    }

    // Print the number of ways to achieve the remainder 5 when the number is divided by 13
    printf("%ld\n", dp[length - 1][5]);
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
