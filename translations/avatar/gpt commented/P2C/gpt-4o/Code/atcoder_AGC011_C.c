#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

typedef struct {
    int *data;
    int top;
} Stack;

void initStack(Stack *s) {
    s->data = (int *)malloc(MAX_NODES * sizeof(int));
    s->top = -1;
}

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int vis[MAX_NODES + 1] = {0};
    int ci = 0, cb = 0, cc = 0;

    // Create an adjacency list to represent the graph
    int **g = (int **)malloc((n + 1) * sizeof(int *));
    int *degree = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        g[i] = (int *)malloc(MAX_NODES * sizeof(int));
        degree[i] = 0;
    }

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][degree[u]++] = v;  // Add edge from u to v
        g[v][degree[v]++] = u;  // Add edge from v to u (undirected graph)
    }

    // Define a depth-first search (DFS) function to check for bipartiteness
    bool dfs(int x) {
        Stack stk;
        initStack(&stk);
        push(&stk, x);
        int color = 1;
        bool flag = true;

        while (!isEmpty(&stk)) {
            int u = pop(&stk);
            if (vis[u]) {
                flag &= (vis[u] == color);
                continue;
            }
            vis[u] = color;
            for (int i = 0; i < degree[u]; i++) {
                push(&stk, g[u][i]);
            }
            color = 3 - color;  // Alternate color
        }
        return flag;
    }

    // Iterate through all nodes to count isolated and bipartite components
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (degree[i] == 0) {
                ci++;  // Increment isolated component counter
            } else {
                if (dfs(i)) {
                    cb++;  // Increment bipartite component counter
                } else {
                    cc++;  // Increment non-bipartite component counter
                }
            }
        }
    }

    // Calculate and print the final result based on the counts of components
    long long result = ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb;
    printf("%lld\n", result);

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(g[i]);
    }
    free(g);
    free(degree);

    return 0;
}

// <END-OF-CODE>
