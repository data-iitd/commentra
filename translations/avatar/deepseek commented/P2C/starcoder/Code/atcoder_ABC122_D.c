#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int mod = 1000000007;
    int memo[n + 1][4];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            memo[i][j] = -1;
        }
    }
    int dfs(int cur, char last3[4]) {
        if (memo[cur][last3[0] - 'A']!= -1) {
            return memo[cur][last3[0] - 'A'];
        }
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            char c = 'A' + i;
            if (ok(last3, c)) {
                ret = (ret + dfs(cur + 1, last3[1] + c)) % mod;
            }
        }
        memo[cur][last3[0] - 'A'] = ret;
        return ret;
    }
    int ok(char last3[4], char c) {
        int count = 0;
        for (int i = 0; i < 3; i++) {
            if (last3[i] == c) {
                count++;
            }
        }
        return count < 2;
    }
    printf("%d", dfs(0, "TTT"));
    return 0;
}

