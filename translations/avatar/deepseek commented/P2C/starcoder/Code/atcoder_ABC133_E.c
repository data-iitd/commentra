#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_N 100000
#define MAX_K 100000
#define MOD 1000000007

int N, K;
int graph[MAX_N][MAX_N];
int dp[MAX_N][MAX_K + 1];

int dfs(int fro, int to, int f) {
    int caseNum = f;
    int colorNum = K - 1;
    if (f == K) {
        colorNum = K - 2;
    }
    for (int i = 0; i < graph[fro][0]; i++) {
        int u = graph[fro][i + 1];
        if (u == to) {
            continue;
        }
        int pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;
        colorNum--;
    }
    return caseNum;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1][graph[a - 1][0]] = b - 1;
        graph[b - 1][graph[b - 1][0]] = a - 1;
        graph[a - 1][0]++;
        graph[b - 1][0]++;
    }
    int ans = dfs(0, -1, K);
    printf("%d", ans);
    return 0;
}

