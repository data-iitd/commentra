#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define MAX_N 100

typedef struct {
    char last3[4];
    long long memo[MAX_N + 1][4][4][4];
} Main;

void init(Main *main, int N) {
    main->N = N;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    main->memo[i][j][k][l] = -1;
                }
            }
        }
    }
}

int isOK(char *last4) {
    if (strstr(last4, "AGC") != NULL) {
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        char vals[5];
        strncpy(vals, last4, i);
        vals[i] = last4[i + 1];
        vals[i + 1] = last4[i];
        vals[i + 2] = last4[i + 2];
        vals[i + 3] = '\0';
        if (strstr(vals, "AGC") != NULL) {
            return 0;
        }
    }
    return 1;
}

long long dfs(Main *main, int current, int a, int b, int c) {
    if (main->memo[current][a][b][c] != -1) {
        return main->memo[current][a][b][c];
    }
    if (current == main->N) {
        return 1;
    }
    long long result = 0;
    char next[5] = "ACGT";
    for (int i = 0; i < 4; ++i) {
        if (isOK(next[i], a, b, c)) {
            result = (result + dfs(main, current + 1, b, c, next[i] - 'A')) % MOD;
        }
    }
    main->memo[current][a][b][c] = result;
    return result;
}

int isOK(char last, char a, char b, char c) {
    char last4[5] = {a, b, c, last, '\0'};
    return isOK(last4);
}

int main() {
    int N;
    scanf("%d", &N);
    Main main;
    init(&main, N);
    printf("%lld\n", dfs(&main, 0, 3, 3, 3));
    return 0;
}
