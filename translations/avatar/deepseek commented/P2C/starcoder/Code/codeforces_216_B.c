#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int g[MAX_N + 1][MAX_N + 1];
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool seen[MAX_N + 1];
        memset(seen, 0, sizeof(seen));
        if (dfs(g, seen, i, 0)) {
            ans++;
        }
    }
    if ((n - ans) % 2 == 1) {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

bool dfs(int g[MAX_N + 1][MAX_N + 1], bool seen[MAX_N + 1], int i, int depth) {
    if (seen[i]) {
        return false;
    }
    seen[i] = true;
    int nodes = 1;
    int edges = 0;
    for (int j = 1; j <= n; j++) {
        if (g[i][j]) {
            edges++;
            if (dfs(g, seen, j, depth + 1)) {
                nodes++;
            }
        }
    }
    if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
        return true;
    }
    return false;
}

