#include <stdio.h>
#include <stdlib.h>

int* readInts() {
    int* arr = (int*)malloc(2 * sizeof(int));
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

void dfs(int** g, int* seen, int i, int* nodes, int* edges) {
    if (seen[i]) {
        return;
    }
    seen[i] = 1;
    (*nodes)++;
    (*edges) += g[i][0];
    for (int j = 1; g[i][j] != 0; j++) {
        dfs(g, seen, g[i][j], nodes, edges);
    }
}

int solve() {
    int* line0 = readInts();
    if (line0 == NULL) {
        return 0;
    }
    int n = line0[0], m = line0[1];
    free(line0);

    int** g = (int**)malloc((n + 1) * sizeof(int*));
    int* seen = (int*)calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++) {
        g[i] = (int*)malloc(n * sizeof(int));
        g[i][0] = 0;
    }

    for (int i = 0; i < m; i++) {
        int* ab = readInts();
        int a = ab[0], b = ab[1];
        free(ab);
        g[a][++g[a][0]] = b;
        g[b][++g[b][0]] = a;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            int nodes = 0, edges = 0;
            dfs(g, seen, i, &nodes, &edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }

    if ((n - ans) % 2 == 1) {
        ans++;
    }
    printf("%d\n", ans);

    for (int i = 1; i <= n; i++) {
        free(g[i]);
    }
    free(g);
    free(seen);

    return 1;
}

int main() {
    while (solve());
    return 0;
}
