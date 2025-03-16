#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100

typedef struct {
    char last3[4];
    long long memo[MAX_N + 1][4][4][4];
} Main;

int isOK(const char *last4) {
    if (strstr(last4, "AGC") != NULL) {
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        char temp[5];
        strncpy(temp, last4, i);
        temp[i] = last4[i + 1];
        temp[i + 1] = last4[i];
        temp[i + 2] = '\0';
        if (strstr(temp, "AGC") != NULL) {
            return 0;
        }
    }
    return 1;
}

long long dfs(Main *main, int current) {
    if (main->memo[current][main->last3[0] - 'A'][main->last3[1] - 'A'][main->last3[2] - 'A'] != -1) {
        return main->memo[current][main->last3[0] - 'A'][main->last3[1] - 'A'][main->last3[2] - 'A'];
    }
    if (current == main->N) {
        return 1;
    }
    long long result = 0;
    const char *tokens = "ACGT";
    for (int i = 0; i < 4; ++i) {
        if (isOK(main->last3 + 1, tokens[i])) {
            main->last3[3] = tokens[i];
            result = (result + dfs(main, current + 1)) % MOD;
        }
    }
    main->memo[current][main->last3[0] - 'A'][main->last3[1] - 'A'][main->last3[2] - 'A'] = result;
    return result;
}

int main() {
    Main main;
    scanf("%d", &main.N);
    for (int i = 0; i <= main.N; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    main.memo[i][j][k][l] = -1;
                }
            }
        }
    }
    strcpy(main.last3, "TTT");
    printf("%lld\n", dfs(&main, 0));
    return 0;
}

