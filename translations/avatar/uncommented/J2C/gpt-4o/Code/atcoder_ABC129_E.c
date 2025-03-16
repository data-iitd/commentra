#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
    char s[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", s);
    
    int n = strlen(s);
    int dp[n + 1][2];
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
        }
        
        if (s[i] == '0') {
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % MOD) % MOD;
        } else {
            dp[i + 1][0] = (dp[i + 1][0] + (dp[i][0] * 2) % MOD) % MOD;
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % MOD) % MOD;
        }
    }

    printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);
    return 0;
}

// <END-OF-CODE>
