#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_LENGTH 100

void run() {
    char cs[MAX_LENGTH];
    scanf("%s", cs);
    int len = strlen(cs);
    long dp[MAX_LENGTH][13] = {0};
    int base = 1;

    for (int i = 0; i < len; ++i) {
        if (cs[len - 1 - i] == '?') {
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            int next = cs[len - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        base = base * 10 % 13;
    }
    printf("%ld\n", dp[len - 1][5]);
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
