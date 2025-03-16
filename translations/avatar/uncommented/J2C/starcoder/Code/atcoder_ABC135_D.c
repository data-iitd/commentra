#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define MOD 1000000007

int main() {
    char cs[1000000];
    scanf("%s", cs);
    int base = 1;
    long dp[1000000][13];
    for (int i = 0; i < strlen(cs); ++i) {
        if (cs[strlen(cs) - 1 - i] == '?') {
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i][(base * next + pre) % 13] += (i > 0? dp[i - 1][pre] : (pre == 0? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            int next = cs[strlen(cs) - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i][(base * next + pre) % 13] += (i > 0? dp[i - 1][pre] : (pre == 0? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        base = base * 10 % 13;
    }
    printf("%ld\n", dp[dp.length - 1][5]);
    return 0;
}

