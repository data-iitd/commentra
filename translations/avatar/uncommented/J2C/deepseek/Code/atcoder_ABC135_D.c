#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

void run(void) {
    char cs[100001];
    int dp[100001][13];
    int base = 1;
    int i, j, k;
    int next;

    scanf("%s", cs);
    int len = strlen(cs);

    memset(dp, 0, sizeof(dp));

    for (i = 0; i < len; ++i) {
        if (cs[len - 1 - i] == '?') {
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            next = cs[len - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        base = base * 10 % 13;
    }

    printf("%d\n", dp[len - 1][5]);
}

int main(void) {
    run();
    return 0;
}
