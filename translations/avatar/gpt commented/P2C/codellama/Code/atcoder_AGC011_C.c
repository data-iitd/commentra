
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read the number of nodes (n) and edges (m) from input
void read_input(int *n, int *m) {
    char str[100];
    fgets(str, 100, stdin);
    sscanf(str, "%d %d", n, m);
}

// Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
void init_vis(int *vis, int n) {
    memset(vis, 0, sizeof(int) * (n + 1));
}

// Create an adjacency list to represent the graph
void create_graph(int **g, int n) {
    int i;
    for (i = 0; i <= n; i++) {
        g[i] = (int *)malloc(sizeof(int) * 10000);
        memset(g[i], 0, sizeof(int) * 10000);
    }
}

// Define a depth-first search (DFS) function to check for bipartiteness
int dfs(int **g, int *vis, int n, int x) {
    int i, u, col, flag = 1;
    int *stk = (int *)malloc(sizeof(int) * 10000);
    stk[0] = x;
    stk[1] = 1;
    int top = 1;
    while (top >= 0) {
        u = stk[top];
        top--;
        if (vis[u]) {
            flag &= (vis[u] == stk[top]);
            continue;
        }
        vis[u] = stk[top];
        for (i = 0; g[u][i]; i++) {
            stk[top + 1] = g[u][i];
            stk[top + 2] = 3 - stk[top];
            top += 2;
        }
    }
    free(stk);
    return flag;
}

// Read edges and build the graph
void read_edges(int **g, int n, int m) {
    int i, u, v;
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        g[u][0] = v;
        g[v][0] = u;
    }
}

// Iterate through all nodes to count isolated and bipartite components
void count_components(int **g, int *vis, int n, int *ci, int *cb, int *cc) {
    int i;
    for (i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (g[i][0] == 0) {
                (*ci)++;
            } else {
                if (dfs(g, vis, n, i)) {
                    (*cb)++;
                } else {
                    (*cc)++;
                }
            }
        }
    }
}

// Calculate and print the final result based on the counts of components
void print_result(int ci, int cb, int cc) {
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
}

int main() {
    int n, m;
    read_input(&n, &m);
    int *vis = (int *)malloc(sizeof(int) * (n + 1));
    int **g = (int **)malloc(sizeof(int *) * (n + 1));
    create_graph(g, n);
    read_edges(g, n, m);
    init_vis(vis, n);
    int ci = 0, cb = 0, cc = 0;
    count_components(g, vis, n, &ci, &cb, &cc);
    print_result(ci, cb, cc);
    return 0;
}

