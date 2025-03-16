

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

#define MOD 1000000007LL

char *TOKENS[] = {"A", "C", "G", "T"};
ll memo[1001][4];

ll dfs(int current, char *last3) {
    if (memo[current][last3[0]-'A']!= -1) {
        return memo[current][last3[0]-'A'];
    }
    if (current == N) {
        return 1;
    }
    ll result = 0;
    for (int i = 0; i < 4; i++) {
        char next = TOKENS[i][0];
        if (next == last3[2] || next == last3[1] || next == last3[0]) {
            continue;
        }
        char new_last3[4];
        new_last3[0] = next;
        new_last3[1] = last3[0];
        new_last3[2] = last3[1];
        new_last3[3] = '\0';
        result = (result + dfs(current + 1, new_last3)) % MOD;
    }
    memo[current][last3[0]-'A'] = result;
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            memo[i][j] = -1;
        }
    }
    printf("%lld\n", dfs(0, "TTT"));
    return 0;
}

