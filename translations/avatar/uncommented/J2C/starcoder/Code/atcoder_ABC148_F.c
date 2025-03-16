#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv)
{
    int N, u, v;
    scanf("%d", &N);
    scanf("%d", &u);
    scanf("%d", &v);
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            edges[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        edges[a - 1][b - 1] = 1;
        edges[b - 1][a - 1] = 1;
    }
    int *d = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u - 1] = 0;
    dfs(u - 1, d, edges);
    int *e = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v - 1] = 0;
    dfs(v - 1, e, edges);
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }
    return 0;
}

void dfs(int u, int *d, int **edges)
{
    for (int i = 0; i < N; i++) {
        if (d[i] == INT_MAX) {
            d[i] = d[u] + 1;
            dfs(i, d, edges);
        }
    }
}

