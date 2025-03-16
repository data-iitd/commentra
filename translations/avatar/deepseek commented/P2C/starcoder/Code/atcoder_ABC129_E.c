#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char l[1000001];
    scanf("%s", l);
    int n = strlen(l);
    int dp[2][2] = {{1, 0}, {0, 1}};
    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            dp[0][0] += dp[0][0];
            dp[0][1] += dp[0][1] * 3;
        } else {
            dp[0][0] += dp[0][0] * 2;
            dp[0][1] += dp[0][0];
            dp[0][1] += dp[0][1] * 3;
        }
        dp[0][0] %= 1000000007;
        dp[0][1] %= 1000000007;
    }
    printf("%d\n", (dp[0][0] + dp[0][1]) % 1000000007);
    return 0;
}

