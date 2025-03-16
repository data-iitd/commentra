
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue.h>

// Define a structure to represent a node in the graph
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define a structure to represent the graph
typedef struct Graph {
    int V;
    Node **adj;
} Graph;

// Create a new graph with n vertices
Graph* createGraph(int n) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V = n;
    g->adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

// Add an edge from u to v in the graph
void addEdge(Graph *g, int u, int v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

// Perform depth-first search (DFS) to check for bipartiteness
bool dfs(Graph *g, int u, int col, int *vis) {
    bool flag = true;
    vis[u] = col;
    Node *curr = g->adj[u];
    while (curr!= NULL) {
        if (vis[curr->data] == -1) {
            flag &= dfs(g, curr->data, 1 - col, vis);
        } else {
            flag &= (vis[curr->data] == 1 - col);
        }
        curr = curr->next;
    }
    return flag;
}

// Count the number of isolated, bipartite, and non-bipartite components
void countComponents(Graph *g, int n, int *ci, int *cb, int *cc) {
    int *vis = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vis[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            if (g->adj[i] == NULL) {
                (*ci)++;
            } else {
                if (dfs(g, i, 0, vis)) {
                    (*cb)++;
                } else {
                    (*cc)++;
                }
            }
        }
    }
    free(vis);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u - 1, v - 1);
        addEdge(g, v - 1, u - 1);  // Add edge in both directions for undirected graph
    }
    int ci = 0, cb = 0, cc = 0;
    countComponents(g, n, &ci, &cb, &cc);
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    return 0;
}

