#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define MAX_N 100
#define MAX_LAST3 4 // To hold last 3 characters + null terminator

char TOKENS[4] = { 'A', 'C', 'G', 'T' };
long memo[MAX_N + 1][1 << 12]; // Memoization array for sequences
int N;

// Function to check if the last four characters form a valid sequence
int isOK(const char* last4) {
    if (strstr(last4, "AGC") != NULL) {
        return 0; // Invalid
    }
    for (int i = 0; i < 3; ++i) {
        char vals[MAX_LAST3];
        strncpy(vals, last4, 4);
        vals[i] = last4[i + 1];
        vals[i + 1] = last4[i];
        vals[3] = '\0'; // Null terminate
        if (strstr(vals, "AGC") != NULL) {
            return 0; // Invalid
        }
    }
    return 1; // Valid
}

// Recursive method to count valid sequences using memoization
long dfs(int current, const char* last3) {
    if (memo[current][(last3[0] << 8) | (last3[1] << 4) | (last3[2])] != -1) {
        return memo[current][(last3[0] << 8) | (last3[1] << 4) | (last3[2])];
    }
    if (current == N) {
        return 1;
    }
    long result = 0;
    for (int i = 0; i < 4; ++i) {
        char c = TOKENS[i];
        char new_last3[MAX_LAST3];
        snprintf(new_last3, MAX_LAST3, "%c%c%c", last3[1], last3[2], c);
        if (isOK(new_last3)) {
            result = (result + dfs(current + 1, new_last3)) % MOD;
        }
    }
    memo[current][(last3[0] << 8) | (last3[1] << 4) | (last3[2])] = result;
    return result;
}

// Main function to run the program
int main() {
    scanf("%d", &N);
    memset(memo, -1, sizeof(memo)); // Initialize memoization array
    printf("%ld\n", dfs(0, "TTT")); // Start with "TTT"
    return 0;
}

// <END-OF-CODE>
