#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define MAX_N 100

char* TOKENS[] = {"A", "C", "G", "T"};

typedef struct {
    int N;
    long memo[MAX_N + 1][4][4][4];
} Main;

int isOK(int last4[4]) {
    if (last4[0] == 1 && last4[1] == 0 && last4[2] == 2 && last4[3] == 3) return 0;
    for (int i = 0; i < 3; ++i) {
        int temp[4];
        memcpy(temp, last4, sizeof(int) * 4);
        temp[i] = last4[i + 1];
        temp[i + 1] = last4[i];
        if (temp[0] == 1 && temp[1] == 0 && temp[2] == 2 && temp[3] == 3) return 0;
    }
    return 1;
}

long dfs(Main* main, int current, int last3[4]) {
    if (main->memo[current][last3[0]][last3[1]][last3[2]] != -1) {
        return main->memo[current][last3[0]][last3[1]][last3[2]];
    }
    if (current == main->N) {
        return 1;
    }
    long result = 0;
    for (int i = 0; i < 4; ++i) {
        int last4[4];
        memcpy(last4, last3, sizeof(int) * 3);
        last4[3] = i;
        if (isOK(last4)) {
            result = (result + dfs(main, current + 1, &last4[1])) % MOD;
        }
    }
    main->memo[current][last3[0]][last3[1]][last3[2]] = result;
    return result;
}

int main() {
    Main main;
    scanf("%d", &main.N);
    memset(main.memo, -1, sizeof(main.memo));
    int last3[4] = {0, 0, 0};
    printf("%ld\n", dfs(&main, 0, last3));
    return 0;
}
