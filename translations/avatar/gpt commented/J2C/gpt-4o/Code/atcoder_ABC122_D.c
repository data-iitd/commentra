#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define MAX_N 100 // Adjust this based on expected maximum N
#define TOKENS_COUNT 4

const char *TOKENS[TOKENS_COUNT] = { "A", "C", "G", "T" };
long memo[MAX_N + 1][1 << 12]; // Memoization array for storing results
int N;

// Function to check if the last 4 characters are valid
int isOK(const char *last4) {
    if (strstr(last4, "AGC") != NULL) {
        return 0; // Invalid
    }
    // Check all permutations of the last 4 characters
    for (int i = 0; i < 3; ++i) {
        char vals[5];
        strncpy(vals, last4, 4);
        vals[4] = '\0';
        // Swap characters to create a new permutation
        char temp = vals[i];
        vals[i] = vals[i + 1];
        vals[i + 1] = temp;
        if (strstr(vals, "AGC") != NULL) {
            return 0; // Invalid
        }
    }
    return 1; // Valid
}

// Depth-first search method to explore all possible sequences
long dfs(int current, const char *last3) {
    // Check if the result is already computed and stored in memo
    if (memo[current][(int)(last3[0] - 'A') * 16 + (int)(last3[1] - 'A') * 4 + (int)(last3[2] - 'A')] != -1) {
        return memo[current][(int)(last3[0] - 'A') * 16 + (int)(last3[1] - 'A') * 4 + (int)(last3[2] - 'A')];
    }
    // Base case: if the current length equals N, return 1 (valid sequence)
    if (current == N) {
        return 1;
    }
    // Variable to accumulate the result
    long result = 0;
    // Iterate through each possible token
    for (int i = 0; i < TOKENS_COUNT; ++i) {
        char new_last3[4];
        snprintf(new_last3, sizeof(new_last3), "%c%c%c", last3[1], last3[2], TOKENS[i][0]);
        // Check if adding the token to the last 3 characters is valid
        if (isOK(new_last3)) {
            // Recursively call dfs for the next character
            result = (result + dfs(current + 1, new_last3)) % MOD;
        }
    }
    // Store the computed result in memoization array
    memo[current][(int)(last3[0] - 'A') * 16 + (int)(last3[1] - 'A') * 4 + (int)(last3[2] - 'A')] = result;
    return result;
}

// Main function to execute the program
int main() {
    // Create a scanner to read input
    scanf("%d", &N);
    // Initialize the memoization array
    memset(memo, -1, sizeof(memo)); // Set all entries to -1 for uncomputed state
    // Start the depth-first search with the initial state
    long result = dfs(0, "TTT");
    // Print the result of the calculation
    printf("%ld\n", result);
    return 0;
}
