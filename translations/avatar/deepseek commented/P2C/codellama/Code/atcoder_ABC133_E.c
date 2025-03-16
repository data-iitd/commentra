#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100000
#define MAX_COLORS 100000
#define MOD 1000000007

typedef struct {
    int *neighbors;
    int numNeighbors;
} Node;

Node *graph;
int N, K;

int dfs(int fro, int to, int f) {
    int caseNum = f;
    int colorNum = K - 1;
    if (f == K) {
        colorNum = K - 2;
    }
    for (int i = 0; i < graph[fro].numNeighbors; i++) {
        int u = graph[fro].neighbors[i];
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
    graph = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        graph[i].neighbors = (int *)malloc(N * sizeof(int));
        graph[i].numNeighbors = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1].neighbors[graph[a - 1].numNeighbors++] = b - 1;
        graph[b - 1].neighbors[graph[b - 1].numNeighbors++] = a - 1;
    }
    int ans = dfs(0, -1, K);
    printf("%d\n", ans);
    return 0;
}
