
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_N 100000
#define MAX_K 100000

int N, K;
int graph[MAX_N][MAX_N];

int dfs(int fro, int to, int f) {
    int caseNum = 1;
    int colorNum = K - 1;
    if (f == K) {
        caseNum = 0;
        colorNum = K - 2;
    }
    for (int i = 0; i < N; i++) {
        if (graph[fro][i] == 1 && i!= to) {
            int pat = dfs(i, fro, colorNum);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = (caseNum * pat) % 1000000007;
            colorNum--;
        }
    }
    return caseNum;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    int ans = dfs(0, -1, K);
    printf("%d\n", ans);
    return 0;
}

