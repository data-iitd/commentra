#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100

long long memo[MAX_N + 1][64]; // 64 is for 4-bit representation of last3
int n;

int ok(const char *last4) {
    // Check if the last 4 characters contain the substring 'AGC'
    for (int i = 0; i < 4; i++) {
        char t[5];
        strcpy(t, last4);
        // Swap the current character with the previous one if not the first character
        if (i >= 1) {
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        // If 'AGC' is found in the modified string, return 0 (false)
        if (strstr(t, "AGC") != NULL) {
            return 0;
        }
    }
    // If 'AGC' is not found in any of the permutations, return 1 (true)
    return 1;
}

long long dfs(int cur, const char *last3) {
    // Check if the result for the current state is already computed
    if (memo[cur][last3[0] - 'A' + (last3[1] - 'A') * 4 + (last3[2] - 'A') * 16] != -1) {
        return memo[cur][last3[0] - 'A' + (last3[1] - 'A') * 4 + (last3[2] - 'A') * 16];
    }
    // If we have reached the end of the sequence, return 1 (valid sequence found)
    if (cur == n) {
        return 1;
    }
    long long ret = 0;
    // Iterate through each possible character 'A', 'C', 'G', 'T'
    for (char c = 'A'; c <= 'T'; c += 2) { // 'A', 'C', 'G', 'T'
        char new_last3[4];
        snprintf(new_last3, sizeof(new_last3), "%c%c%c", last3[1], last3[2], c);
        // Check if adding the current character keeps the sequence valid
        if (ok(new_last3)) {
            // Recursively call dfs for the next position with the updated last3
            ret = (ret + dfs(cur + 1, new_last3)) % MOD;
        }
    }
    // Store the computed result in the memoization table
    memo[cur][last3[0] - 'A' + (last3[1] - 'A') * 4 + (last3[2] - 'A') * 16] = ret;
    return ret;
}

int main() {
    // Read the length of the sequence from input
    scanf("%d", &n);
    // Initialize the memoization table
    memset(memo, -1, sizeof(memo));
    // Start the depth-first search with the initial state
    char initial_last3[4] = "TTT";
    printf("%lld\n", dfs(0, initial_last3));
    return 0;
}

// <END-OF-CODE>
