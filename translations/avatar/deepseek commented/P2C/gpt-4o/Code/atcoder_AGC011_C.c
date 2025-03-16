#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100005

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

int g[MAX_NODES][MAX_NODES];
int vis[MAX_NODES];
int n, m, ci = 0, cb = 0, cc = 0;

bool dfs(int x) {
    Stack stk;
    initStack(&stk);
    push(&stk, x);
    push(&stk, 1); // Start with color 1
    bool flag = true;

    while (!isEmpty(&stk)) {
        int col = pop(&stk);
        int u = pop(&stk);

        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }
        vis[u] = col;

        for (int i = 0; i < n; i++) {
            if (g[u][i]) { // If there is an edge
                push(&stk, 3 - col); // Opposite color
                push(&stk, i); // Adjacent node
            }
        }
    }
    free(stk.data);
    return flag;
}

int main() {
    scanf("%d %d", &n, &m);
    
    // Initialize graph
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            g[i][j] = 0; // No edges initially
        }
    }

    // Constructing the graph by reading edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1; // Adding edge u-v
        g[v][u] = 1; // Adding edge v-u (undirected graph)
    }

    // Traversing the graph to classify nodes
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) { // If the node has not been visited
            if (g[i][0] == 0) {
                ci++; // Increment the count of isolated nodes
            } else {
                if (dfs(i)) {
                    cb++; // Increment the count of bipartite graphs
                } else {
                    cc++; // Increment the count of connected components that are not bipartite
                }
            }
        }
    }

    // Calculating and printing the result based on the counts of isolated, bipartite, and connected components
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);

    return 0;
}

// <END-OF-CODE>
