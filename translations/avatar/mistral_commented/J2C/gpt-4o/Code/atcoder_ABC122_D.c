#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define MAX_N 1000
#define TOKENS_SIZE 4

char *TOKENS[TOKENS_SIZE] = { "A", "C", "G", "T" };
long memo[MAX_N + 1][1 << 12]; // Using bitmasking for last 3 nucleotides
int N;

long dfs(int current, int last3) {
    if (memo[current][last3] != -1) {
        return memo[current][last3];
    }

    if (current == N) {
        return 1;
    }

    long result = 0;

    for (int i = 0; i < TOKENS_SIZE; i++) {
        int nextNucleotide = (last3 << 2) | i; // Shift last 3 nucleotides and add new one
        if (isOK(nextNucleotide)) {
            result = (result + dfs(current + 1, nextNucleotide)) % MOD;
        }
    }

    memo[current][last3] = result;
    return result;
}

int isOK(int last3) {
    // Convert last 3 nucleotides to string
    char last4[5];
    last4[3] = '\0';
    for (int i = 0; i < 3; i++) {
        last4[i] = TOKENS[(last3 >> (2 * (2 - i))) & 3][0];
    }

    if (strstr(last4, "AGC") != NULL) {
        return 0; // Invalid
    }

    for (int i = 0; i < 2; i++) {
        char temp[5];
        strcpy(temp, last4);
        char swap = temp[i];
        temp[i] = temp[i + 1];
        temp[i + 1] = swap;

        if (strstr(temp, "AGC") != NULL) {
            return 0; // Invalid
        }
    }

    return 1; // Valid
}

int main() {
    scanf("%d", &N);

    // Initialize memoization table
    memset(memo, -1, sizeof(memo));

    long result = dfs(0, 0); // Start with current = 0 and last3 = 0
    printf("%ld\n", result);

    return 0;
}
