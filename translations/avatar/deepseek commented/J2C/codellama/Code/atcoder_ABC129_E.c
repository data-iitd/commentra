#include <stdio.h>
#include <string.h>

#define M 1000000007

int main() {
    char s[100000];
    int n, i, j, dp[100000][2];

    scanf("%s", s);
    n = strlen(s);
    dp[0][0] = 1;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M;
        }

        if (s[i] == '0') {
            dp[i + 1][1] += (dp[i][1] * 2) % M;
            dp[i + 1][1] %= M;
        } else {
            dp[i + 1][0] += (dp[i][0] * 2) % M;
            dp[i + 1][1] += (dp[i][1] * 2) % M;
            dp[i + 1][0] %= M;
            dp[i + 1][1] %= M;
        }
    }

    printf("%d\n", (dp[n][0] + dp[n][1]) % M);

    return 0;
}

