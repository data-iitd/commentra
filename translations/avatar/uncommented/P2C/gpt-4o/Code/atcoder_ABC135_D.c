#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 1000000

long long dp[MAX_N][13];

int main() {
    char S[MAX_N];
    scanf("%s", S);
    int n = strlen(S);

    if (n == 1) {
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (S[i] != '?') {
                dp[i][S[i] - '0'] += 1;
            } else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        } else {
            if (S[i] != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + (S[i] - '0')) % 13] %= MOD;
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + j) % 13] %= MOD;
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[n - 1][5]);
    return 0;
}

// <END-OF-CODE>
