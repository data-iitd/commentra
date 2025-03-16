
#include <stdio.h>
#include <stdlib.h>
#include <queue>

int main() {
    int N;
    scanf("%d", &N);

    int **adj = (int **)malloc(sizeof(int *) * (N + 1));
    for (int i = 0; i <= N; i++) {
        adj[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    std::queue<int> que;
    que.push(1);
    int *seen = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i <= N; i++) {
        seen[i] = 0;
    }
    seen[1] = 1;

    int *par = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i <= N; i++) {
        par[i] = 0;
    }

    int *child_num = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i <= N; i++) {
        child_num[i] = 0;
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int u = 1; u <= N; u++) {
            if (adj[v][u] == 1 && seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v] += 1;
                que.push(u);
            }
        }
    }

    std::queue<int> seq;
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            seq.push(i);
        }
    }

    while (!seq.empty()) {
        int c = seq.front();
        seq.pop();
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]] -= 1;
        if (child_num[par[par[c]]] == 0) {
            seq.push(par[par[c]]);
        }
    }

    printf("Second\n");

    return 0;
}
