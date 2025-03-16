#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int ok(char* last4) {
    // Check if the last4 string contains "AGC" more than once
    for (int i = 0; i < 4; i++) {
        char t[5];
        strcpy(t, last4);
        if (i >= 1) {
            // Swap the current and previous character
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        if (strstr(t, "AGC") != NULL) {
            // If "AGC" is found, return 0 (False)
            return 0;
        }
    }
    return 1; // Valid sequence
}

int dfs(int cur, char* last3, int memo[51][16], int mod) {
    // Check if the result for the current state (cur, last3) is already computed
    if (memo[cur][0] != -1) {
        return memo[cur][0];
    }
    if (cur == n) {
        // Base case: if current length equals n, return 1 (valid sequence)
        return 1;
    }
    int ret = 0;
    char c;
    for (c = 'A'; c <= 'Z'; c++) {
        // Check if adding the character c to last3 forms a valid sequence
        if (ok(last3) && c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            continue;
        }
        if (ok(last3 + c)) {
            // Recursively call dfs with the next character
            ret = (ret + dfs(cur + 1, last3 + 1, memo, mod)) % mod;
        }
    }
    memo[cur][0] = ret;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int memo[51][16];
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j < 16; j++) {
            memo[i][j] = -1;
        }
    }
    printf("%d\n", dfs(0, "TTT", memo, MOD));
    return 0;
}
