#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100

int n;
int memo[MAX_N + 1][1 << 12]; // Using bitmasking for memoization
char last3[4];

int ok(const char *last4) {
    for (int i = 0; i < 4; i++) {
        char t[5];
        strcpy(t, last4);
        if (i >= 1) {
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        if (strstr(t, "AGC") != NULL) {
            return 0; // False
        }
    }
    return 1; // True
}

int dfs(int cur, const char *last3) {
    if (memo[cur][last3[0] << 8 | last3[1] << 4 | last3[2]] != -1) {
        return memo[cur][last3[0] << 8 | last3[1] << 4 | last3[2]];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    for (char c = 'A'; c <= 'T'; c++) {
        char new_last3[4];
        snprintf(new_last3, sizeof(new_last3), "%c%c%c", last3[1], last3[2], c);
        if (ok(new_last3)) {
            ret = (ret + dfs(cur + 1, new_last3)) % MOD;
        }
    }
    memo[cur][last3[0] << 8 | last3[1] << 4 | last3[2]] = ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    memset(memo, -1, sizeof(memo));
    strcpy(last3, "TTT");
    printf("%d\n", dfs(0, last3));
    return 0;
}

// <END-OF-CODE>
