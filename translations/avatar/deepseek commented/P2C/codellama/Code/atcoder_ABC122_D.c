#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ok(char *last4) {
    // Check if the last4 string contains "AGC" more than once
    for (int i = 0; i < 4; i++) {
        char t[5];
        strcpy(t, last4);
        if (i >= 1) {
            // Swap the current and previous character
            t[i] = last4[i - 1];
            t[i - 1] = last4[i];
        }
        if (strstr(t, "AGC") != NULL) {
            // If "AGC" is found, return False
            return 0;
        }
    }
    return 1;
}

int dfs(int cur, char *last3) {
    // Check if the result for the current state (cur, last3) is already computed
    if (memo[cur][last3] != -1) {
        return memo[cur][last3];
    }
    if (cur == n) {
        // Base case: if current length equals n, return 1 (valid sequence)
        return 1;
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        // Check if adding the character c to last3 forms a valid sequence
        char c = "ACGT"[i];
        if (ok(last3 + c)) {
            // Recursively call dfs with the next character
            ret = (ret + dfs(cur + 1, last3[1] + c)) % mod;
        }
    }
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    // Read the input value for n
    scanf("%d", &n);
    mod = 1000000007;
    // Initialize the memo dictionary for storing computed results
    memo = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++) {
        memo[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++) {
            memo[i][j] = -1;
        }
    }
    // Print the result of the dfs function starting with last3 as "TTT"
    printf("%d\n", dfs(0, "TTT"));
    return 0;
}

