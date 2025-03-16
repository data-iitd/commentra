#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 1000000

// Function to read an integer
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string
void read_string(char *str, int size) {
    scanf("%s", str);
}

int main() {
    // Input the string S
    char S[MAX_N];
    read_string(S, MAX_N);
    int n = strlen(S);

    // Base case: if the length of the string is 1
    if (n == 1) {
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }

    // Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
    long long dp[n][13];
    memset(dp, 0, sizeof(dp));

    // Iterate through each index i from 0 to n-1
    for (int i = 0; i < n; i++) {
        // If i is the first index, process it differently
        if (i == 0) {
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i] != '?') {
                dp[i][S[i] - '0'] += 1;
            } else {
                // If the character at index i is '?', update all elements in the dp array accordingly
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        } else {
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i] != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + (S[i] - '0')) % 13] %= MOD;
                }
            } else {
                // If the character at index i is '?', update all elements in the dp array accordingly
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + j) % 13] %= MOD;
                    }
                }
            }
        }
    }

    // Print the final answer, which is dp[n-1][5]
    printf("%lld\n", dp[n - 1][5]);

    return 0;
}

// <END-OF-CODE>
