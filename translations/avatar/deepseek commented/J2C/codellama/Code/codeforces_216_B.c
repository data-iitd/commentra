
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int count;
    bool *seen;
    int path;
    int cycle;
    int m;
    int n;
    int toremove;
    int **graph;
} Main;

int dfs(Main *ft, int child, int par) {
    if (ft->seen[child]) return ft->cycle;
    ft->seen[child] = true;
    for (int i = 0; i < ft->n; i++) {
        if (ft->graph[child][i] != par) {
            ft->count++;
            if (dfs(ft, ft->graph[child][i], child) == ft->cycle) return ft->cycle;
        }
    }
    return ft->path;
}

int main() {
    Main ft;
    int m, n;
    scanf("%d %d", &m, &n);
    ft.graph = (int **) malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        ft.graph[i] = (int *) malloc((m + 1) * sizeof(int));
        memset(ft.graph[i], 0, (m + 1) * sizeof(int));
    }
    ft.seen = (bool *) malloc((m + 1) * sizeof(bool));
    memset(ft.seen, 0, (m + 1) * sizeof(bool));
    ft.count = 0;
    ft.path = 0;
    ft.cycle = 1;
    ft.m = m;
    ft.n = n;
    ft.toremove = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ft.graph[x][y] = 1;
        ft.graph[y][x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        if (!ft.seen[i]) {
            ft.count = 0;
            if (dfs(&ft, i, 0) == ft.cycle) {
                if (ft.count % 2 == 1) ft.toremove++;
            }
        }
    }
    if ((m - ft.toremove) % 2 == 1) ft.toremove++;
    printf("%d\n", ft.toremove);
    return 0;
}

