#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX_N 100

// Memoization table
int memo[MAX_N + 1][64]; // 64 is 4^3 for last3 combinations
bool visited[MAX_N + 1][64];

// Function to check if the last 4 nucleotides contain "AGC"
bool ok(const char *last4) {
    for (int i = 0; i < 4; i++) {
        char t[5];
        strcpy(t, last4);
        if (i >= 1) {
            // Swap the positions of the current and previous nucleotides
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        // Check if the swapped sequence contains "AGC"
        if (strstr(t, "AGC") != NULL) {
            return false; // Return false if "AGC" is found
        }
    }
    return true; // Return true if "AGC" is not found
}

// Function to perform Depth-First Search (DFS)
int dfs(int cur, const char *last3) {
    // Convert last3 to an index for memoization
    int index = (last3[0] - 'A') * 16 + (last3[1] - 'A') * 4 + (last3[2] - 'A');
    
    // Check if the subproblem has already been solved
    if (visited[cur][index]) {
        return memo[cur][index];
    }
    
    // Base case: If we have reached the end of the sequence, return 1
    if (cur == n) {
        return 1;
    }
    
    // Initialize the result to 0
    int ret = 0;
    
    // Iterate through all possible nucleotides (A, C, G, T)
    for (char c = 'A'; c <= 'T'; c += 3) { // A, C, G, T
        char new_last3[4] = {last3[1], last3[2], c, '\0'};
        // Check if the next nucleotide can be added to the last 3 nucleotides
        if (ok(new_last3)) {
            // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur + 1, new_last3)) % MOD;
        }
    }
    
    // Store the result in the memoization table and mark as visited
    memo[cur][index] = ret;
    visited[cur][index] = true;
    return ret;
}

int main() {
    // Read the input: the number of nucleotides (n)
    scanf("%d", &n);
    
    // Initialize the memoization table and visited array
    memset(memo, 0, sizeof(memo));
    memset(visited, false, sizeof(visited));
    
    // Perform DFS and print the result
    printf("%d\n", dfs(0, "TTT"));
    
    return 0;
}

// <END-OF-CODE>
