#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

int n, m;
int vis[MAXN + 1] = {0};
int ci = 0, cb = 0, cc = 0;
int g[MAXN + 1][MAXN + 1] = {0};

// Depth-First Search (DFS) function to determine if a graph is bipartite
bool dfs(int x, int col) {
    int stack[MAXN * MAXN], top = 0;
    bool flag = true;
    stack[top++] = x;
    vis[x] = col;

    while (top > 0) {
        int u = stack[--top];
        int current_col = vis[u];

        for (int i = 1; i <= n; i++) {
            if (g[u][i] == 1) {
                if (vis[i] == 0) {
                    stack[top++] = i;
                    vis[i] = 3 - current_col;
                } else {
                    flag &= (vis[i] == 3 - current_col);
                }
            }
        }
    }
    return flag;
}

int main() {
    scanf("%d %d", &n, &m);

    // Constructing the graph by reading edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }

    // Traversing the graph to classify nodes
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (g[i][0] == 0) {
                ci++;
            } else {
                if (dfs(i, 1)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }

    // Calculating and printing the result based on the counts of isolated, bipartite, and connected components
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);

    return 0;
}
