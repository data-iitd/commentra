#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main() {
    char s[1000000];
    scanf("%s", s);
    int n = strlen(s);
    long dp[n][13];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 13; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[n - 1 - i] == '?') {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i][(j * 13 + k) % 13] += (i > 0? dp[i - 1][k] : (k == 0? 1 : 0));
                    dp[i][(j * 13 + k) % 13] %= MOD;
                }
            }
        } else {
            int num = s[n - 1 - i] - '0';
            for (int j = 0; j < 13; j++) {
                dp[i][(num * 13 + j) % 13] += (i > 0? dp[i - 1][j] : (j == 0? 1 : 0));
                dp[i][(num * 13 + j) % 13] %= MOD;
            }
        }
    }
    printf("%ld\n", dp[n - 1][5]);
    return 0;
}

