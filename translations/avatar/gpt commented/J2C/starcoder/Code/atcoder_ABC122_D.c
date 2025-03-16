#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define N 100000
#define TOKENS "ACGT"

typedef struct {
    char last3[4];
    long result;
} memo_t;

int main() {
    int i, j;
    char last3[4];
    long result, total;
    memo_t memo[N];

    for (i = 0; i < N; i++) {
        memo[i].result = 0;
        memo[i].last3[0] = 'T';
        memo[i].last3[1] = 'T';
        memo[i].last3[2] = 'T';
        memo[i].last3[3] = '\0';
    }

    for (i = 0; i < N; i++) {
        if (memo[i].result!= 0) {
            continue;
        }

        for (j = 0; j < 4; j++) {
            if (i == 0) {
                result = 1;
            } else {
                result = 0;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'A' && memo[i - 1].last3[1] == 'G' && memo[i - 1].last3[2] == 'C') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'A' && memo[i - 1].last3[1] == 'C' && memo[i - 1].last3[2] == 'G') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'A' && memo[i - 1].last3[1] == 'C' && memo[i - 1].last3[2] == 'T') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'A' && memo[i - 1].last3[1] == 'G' && memo[i - 1].last3[2] == 'T') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'A' && memo[i - 1].last3[1] == 'T' && memo[i - 1].last3[2] == 'C') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'A' && memo[i - 1].last3[1] == 'T' && memo[i - 1].last3[2] == 'G') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'C' && memo[i - 1].last3[1] == 'A' && memo[i - 1].last3[2] == 'G') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'C' && memo[i - 1].last3[1] == 'A' && memo[i - 1].last3[2] == 'T') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'C' && memo[i - 1].last3[1] == 'G' && memo[i - 1].last3[2] == 'A') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'C' && memo[i - 1].last3[1] == 'G' && memo[i - 1].last3[2] == 'T') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'C' && memo[i - 1].last3[1] == 'T' && memo[i - 1].last3[2] == 'A') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'C' && memo[i - 1].last3[1] == 'T' && memo[i - 1].last3[2] == 'G') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'G' && memo[i - 1].last3[1] == 'A' && memo[i - 1].last3[2] == 'C') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'G' && memo[i - 1].last3[1] == 'A' && memo[i - 1].last3[2] == 'T') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'G' && memo[i - 1].last3[1] == 'C' && memo[i - 1].last3[2] == 'A') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'G' && memo[i - 1].last3[1] == 'C' && memo[i - 1].last3[2] == 'T') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'G' && memo[i - 1].last3[1] == 'T' && memo[i - 1].last3[2] == 'A') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'G' && memo[i - 1].last3[1] == 'T' && memo[i - 1].last3[2] == 'C') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'T' && memo[i - 1].last3[1] == 'A' && memo[i - 1].last3[2] == 'C') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'T' && memo[i - 1].last3[1] == 'A' && memo[i - 1].last3[2] == 'G') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'T' && memo[i - 1].last3[1] == 'C' && memo[i - 1].last3[2] == 'A') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'T' && memo[i - 1].last3[1] == 'C' && memo[i - 1].last3[2] == 'G') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'T' && memo[i - 1].last3[1] == 'G' && memo[i - 1].last3[2] == 'A') {
                continue;
            }

            if (i > 0 && memo[i - 1].last3[0] == 'T' && memo[i - 1].last3[1] == 'G' && memo[i - 1].last3[2] == 'C') {
                continue;
            }

            strcpy(last3, memo[i - 1].last3);
            strcat(last3, TOKENS[j]);
            if (i > 0 && last3[0] == 'A' && last3[1] == 'G' && last3[2] == 'C') {
                continue;
            }

            if (i > 0 && last3[0] == 'A' && last3[1] == 'C' && last3[2] == 'G') {
                continue;
            }

            if (i > 0 && last3[0] == 'A' && last3[1] == 'C' && last3[2] == 'T') {
                continue;
            }

            if (i > 0 && last3[0] == 'A' && last3[1] == 'G' && last3[2] == 'T') {
                continue;
            }

            if (i > 0 && last3[0] == 'A' && last3[1] == 'T' && last3[2] == 'C') {
                continue;
            }

            if (i > 0 && last3[0] == 'A' && last3[1] == 'T' && last3[2] == 'G') {
                continue;
            }

            if (i > 0 && last3[0] == 'C' && last3[1] == 'A' && last3[2] == 'G') {
                continue;
            }

            if (i > 0 && last3[0] == 'C' && last3[1] == 'A' && last3[2] == 'T') {
                continue;
            }

            if (i > 0 && last3[0] == 'C' && last3[1] == 'G' && last3[2] == 'A') {
                continue;
            }

            if (i > 0 && last3[0] == 'C' && last3[1] == 'G' && last3[2] == 'T') {
                continue;
            }

            if (i > 0 && last3[0] == 'C' && last3[1] == 'T' && last3[2] == 'A') {
                continue;
            }

            if (i > 0 && last3[0] == 'C' && last3[1] == 'T' && last3[2] == 'G') {
                continue;
            }

            if (i > 0 && last3[0] == 'G' && last3[1] == 'A' && last3[2] == 'C') {
                continue;
            }

            if (i > 0 && last3[0] == 'G' && last3[1] == 'A' && last3[2] == 'T') {
                continue;
            }

            if (i > 0 && last3[0] == 'G' && last3[1] == 'C' && last3[2] == 'A') {
                continue;
            }

            if (i > 0 && last3[0] == 'G' && last3[1] == 'C' && last3[2] == 'T') {
                continue;
            }

            if (i > 0 && last3[0] == 'G' && last3[1] == 'T' && last3[2] == 'A') {
                continue;
            }

            if (i > 0 && last3[0] == 'G' && last3[1] == 'T' && last3[2] == 'C') {
                continue;
            }

            if (i > 0 && last3[0] == 'T' && last3[1] == 'A' && last3[2] == 'C') {
                continue;
            }

            if (i > 0 && last3[0] == 'T' && last3[1] == 'A' && last3[2] == 'G') {
                continue;
            }

            if (i > 0 && last3[0] == 'T' && last3[1] == 'C' && last3[2] == 'A') {
                continue;
            }

            if (i > 0 && last3[0] == 'T' && last3[1] == 'C' && last3[2] == 'G') {
                continue;
            }

            if (i > 0 && last3[0] == 'T' && last3[1] == 'G' && last3[2] == 'A') {
                continue;
            }

            if (i > 0 && last3[0] == 'T' && last3[1] == 'G' && last3[2] == 'C') {
                continue;
            }

            result = (result + dfs(i + 1, last3)) % MOD;
        }

        memo[i].result = result;
    }

    total = 0;
    for (i = 0; i < N; i++) {
        total = (total + memo[i].result) % MOD;
    }

    printf("%ld\n", total);

    return 0;
}

