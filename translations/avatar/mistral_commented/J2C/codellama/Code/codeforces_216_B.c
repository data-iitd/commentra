
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int count;
    bool* seen;
    int path;
    int cycle;
    int m;
    int n;
    int toremove;
    int** graph;
} Main;

int dfs(Main* ft, int child, int par) {
    if (ft->seen[child] == true) {
        return ft->cycle;
    }
    ft->seen[child] = true;

    for (int i = 0; i < ft->n; i++) {
        if (ft->graph[child][i] != par) {
            ft->count++;
            if (dfs(ft, ft->graph[child][i], child) == ft->cycle) {
                return ft->cycle;
            }
        }
    }
    return ft->path;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    Main* ft = (Main*)malloc(sizeof(Main));
    ft->graph = (int**)malloc(sizeof(int*) * (m + 1));
    ft->seen = (bool*)malloc(sizeof(bool) * (m + 1));
    ft->count = 0;
    ft->path = 0;
    ft->cycle = 1;
    ft->m = m;
    ft->n = n;
    ft->toremove = 0;

    for (int i = 0; i <= m; i++) {
        ft->graph[i] = (int*)malloc(sizeof(int) * (m + 1));
        for (int j = 0; j <= m; j++) {
            ft->graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ft->graph[x][y] = 1;
        ft->graph[y][x] = 1;
    }

    for (int i = 1; i <= m; i++) {
        if (!ft->seen[i]) {
            ft->count = 0;
            if (dfs(ft, i, 0) == ft->cycle) {
                if (ft->count % 2 == 1) {
                    ft->toremove++;
                }
            }
        }
    }

    if ((m - ft->toremove) % 2 == 1) {
        ft->toremove++;
    }

    printf("%d\n", ft->toremove);
    return 0;
}

