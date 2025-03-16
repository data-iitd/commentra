#include <stdio.h>
#include <string.h>

#define mod 1000000007

int main () {
    int l, n, i, j, dp[100001][2];
    char c;

    scanf ("%d", &l);
    n = strlen (l);

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (i = 0; i < n; i++) {
        scanf ("%c", &c);
        if (c == '0') {
            dp[i + 1][0] = (dp[i][0] + dp[i][1] * 3) % mod;
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
        } else {
            dp[i + 1][0] = (dp[i][0] * 2 + dp[i][1] * 3) % mod;
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
        }
    }

    printf ("%d", (dp[n][0] + dp[n][1]) % mod);

    return 0;
}

