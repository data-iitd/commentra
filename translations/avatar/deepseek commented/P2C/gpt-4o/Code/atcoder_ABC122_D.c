#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100
#define MAX_LAST3 4

long long memo[MAX_N + 1][1 << (2 * MAX_LAST3)]; // Memoization table
int n;

// Function to check if the last 4 characters contain "AGC"
int ok(const char *last4) {
    for (int i = 0; i < 4; i++) {
        char t[5]; // Temporary array to hold the last 4 characters + null terminator
        strncpy(t, last4, 4);
        t[4] = '\0'; // Null-terminate the string
        if (i >= 1) {
            // Swap the current and previous character
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        // Check if "AGC" is found in the modified string
        if (strstr(t, "AGC") != NULL) {
            return 0; // Return false
        }
    }
    return 1; // Return true
}

// Depth-first search function
long long dfs(int cur, const char *last3) {
    // Check if the result for the current state (cur, last3) is already computed
    if (memo[cur][(last3[0] << 6) | (last3[1] << 4) | (last3[2] << 2)] != -1) {
        return memo[cur][(last3[0] << 6) | (last3[1] << 4) | (last3[2] << 2)];
    }
    if (cur == n) {
        // Base case: if current length equals n, return 1 (valid sequence)
        return 1;
    }
    long long ret = 0;
    for (char c = 'A'; c <= 'T'; c++) {
        // Check if adding the character c to last3 forms a valid sequence
        char new_last3[4] = {last3[1], last3[2], last3[3], c};
        if (ok(new_last3)) {
            // Recursively call dfs with the next character
            ret = (ret + dfs(cur + 1, new_last3)) % MOD;
        }
    }
    memo[cur][(last3[0] << 6) | (last3[1] << 4) | (last3[2] << 2)] = ret;
    return ret;
}

int main() {
    // Read the input value for n
    scanf("%d", &n);
    // Initialize the memoization table with -1
    memset(memo, -1, sizeof(memo));
    // Print the result of the dfs function starting with last3 as "TTT"
    char last3[4] = {'T', 'T', 'T', '\0'};
    printf("%lld\n", dfs(0, last3));
    return 0;
}

// <END-OF-CODE>
