#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_MOD 1000000007

int memo[MAX_N][4];

int ok(char *last4) {
    // Check if the last 4 characters contain the substring 'AGC'
    for (int i = 0; i < 4; i++) {
        // Create a list from the last4 string to allow swapping
        char t[5];
        strcpy(t, last4);
        // Swap the current character with the previous one if not the first character
        if (i >= 1) {
            t[i] = t[i - 1];
            t[i - 1] = last4[i];
        }
        // If 'AGC' is found in the modified string, return False
        if (strstr(t, "AGC") != NULL) {
            return 0;
        }
    }
    // If 'AGC' is not found in any of the permutations, return True
    return 1;
}

int dfs(int cur, char *last3) {
    // Check if the result for the current state is already computed
    if (memo[cur][last3[0] - 'A'] != -1) {
        return memo[cur][last3[0] - 'A'];
    }
    // If we have reached the end of the sequence, return 1 (valid sequence found)
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    // Iterate through each possible character 'A', 'C', 'G', 'T'
    for (int i = 0; i < 4; i++) {
        // Check if adding the current character keeps the sequence valid
        if (ok(last3 + last3[0])) {
            // Recursively call dfs for the next position with the updated last3
            ret = (ret + dfs(cur + 1, last3 + 1)) % MAX_MOD;
        }
    }
    // Store the computed result in the memoization table
    memo[cur][last3[0] - 'A'] = ret;
    return ret;
}

int main() {
    // Read the length of the sequence from input
    scanf("%d", &n);
    // Initialize the memoization table
    memset(memo, -1, sizeof(memo));
    // Start the depth-first search with the initial state
    printf("%d\n", dfs(0, "TTT"));
    return 0;
}

