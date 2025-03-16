
#include <stdio.h>
#include <string.h>

#define MOD 100000007

int ok(char *last4) {
    // Check if the last 4 characters contain the substring 'AGC'
    for (int i = 0; i < 4; i++) {
        // Create a copy of the last4 string to allow swapping
        char t[5];
        strcpy(t, last4);
        // Swap the current character with the previous one if not the first character
        if (i >= 1) {
            char tmp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = tmp;
        }
        // If 'AGC' is found in the modified string, return False
        if (strstr(t, "AGC")) {
            return 0;
        }
    }
    // If 'AGC' is not found in any of the permutations, return True
    return 1;
}

int dfs(int cur, char *last3) {
    // Check if the result for the current state is already computed
    if (last3[0] && memo[cur][last3[0]][last3[1]][last3[2]]) {
        return memo[cur][last3[0]][last3[1]][last3[2]];
    }
    // If we have reached the end of the sequence, return 1 (valid sequence found)
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    // Iterate through each possible character 'A', 'C', 'G', 'T'
    for (char c = 'A'; c <= 'T'; c++) {
        // Check if adding the current character keeps the sequence valid
        if (ok(last3 + c)) {
            // Recursively call dfs for the next position with the updated last3
            ret = (ret + dfs(cur + 1, last3 + 1)) % MOD;
        }
    }
    // Store the computed result in the memoization table
    memo[cur][last3[0]][last3[1]][last3[2]] = ret;
    return ret;
}

int main() {
    // Read the length of the sequence from input
    scanf("%d", &n);
    // Initialize the memoization table
    memset(memo, 0, sizeof(memo));
    // Start the depth-first search with the initial state
    printf("%d\n", dfs(0, "TTT"));
    return 0;
}
