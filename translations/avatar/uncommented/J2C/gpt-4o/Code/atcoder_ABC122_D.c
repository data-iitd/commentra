#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define MAX_N 100
#define MAX_LAST3 4 // "TTT" + 1 for the new character

char TOKENS[4] = {'A', 'C', 'G', 'T'};
long memo[MAX_N + 1][1 << 12]; // Using bitmasking for last 3 characters
int N;

int isOK(char *last4) {
    if (strstr(last4, "AGC") != NULL) {
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        char vals[5];
        strcpy(vals, last4);
        char temp = vals[i];
        vals[i] = vals[i + 1];
        vals[i + 1] = temp;
        if (strstr(vals, "AGC") != NULL) {
            return 0;
        }
    }
    return 1;
}

long dfs(int current, char *last3) {
    if (memo[current][last3[0] * 256 + last3[1] * 16 + last3[2]] != -1) {
        return memo[current][last3[0] * 256 + last3[1] * 16 + last3[2]];
    }
    if (current == N) {
        return 1;
    }
    long result = 0;
    for (int i = 0; i < 4; ++i) {
        char new_last3[4];
        snprintf(new_last3, sizeof(new_last3), "%c%c%c", last3[1], last3[2], TOKENS[i]);
        if (isOK(new_last3)) {
            result = (result + dfs(current + 1, new_last3)) % MOD;
        }
    }
    memo[current][last3[0] * 256 + last3[1] * 16 + last3[2]] = result;
    return result;
}

long calc() {
    char last3[4] = "TTT";
    return dfs(0, last3);
}

int main() {
    scanf("%d", &N);
    memset(memo, -1, sizeof(memo)); // Initialize memoization array
    printf("%ld\n", calc());
    return 0;
}
