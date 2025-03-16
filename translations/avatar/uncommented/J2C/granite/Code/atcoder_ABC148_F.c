
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dfs(int u, int d[], int edges[100][100], int N) {
    for (int i = 0; i < N; i++) {
        if (d[i] == INT_MAX && edges[u][i] == 1) {
            d[i] = d[u] + 1;
            dfs(i, d, edges, N);
        }
    }
}

int main() {
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--;
    v--;
    int edges[100][100] = {0};
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int d[100] = {0};
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    dfs(u, d, edges, N);
    int e[100] = {0};
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v] = 0;
    dfs(v, e, edges, N);
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i] && e[i] > q) {
            q = e[i];
        }
    }
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }
    return 0;
}
