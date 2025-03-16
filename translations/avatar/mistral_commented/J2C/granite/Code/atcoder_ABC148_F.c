

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum number of nodes
#define MAX_N 100000

// Define the maximum number of edges
#define MAX_M 100000

// Define the structure of the adjacency list
typedef struct {
    int to;
    struct Edge *next;
} Edge;

// Define the structure of the graph
typedef struct {
    Edge *edges[MAX_N];
    int n;
    int m;
} Graph;

// Initialize the graph
void initGraph(Graph *g) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        g->edges[i] = NULL;
    }
    g->n = 0;
    g->m = 0;
}

// Add an edge to the graph
void addEdge(Graph *g, int u, int v) {
    Edge *e = (Edge *)malloc(sizeof(Edge));
    e->to = v;
    e->next = g->edges[u];
    g->edges[u] = e;
    g->m++;
}

// Perform depth-first search from a given node and store the distances in an array
void dfs(int u, int *d, Graph *g) {
    Edge *e;
    for (e = g->edges[u]; e!= NULL; e = e->next) {
        if (d[e->to] == INT_MAX) {
            d[e->to] = d[u] + 1;
            dfs(e->to, d, g);
        }
    }
}

int main() {
    // Read the number of nodes N from the standard input
    int N;
    scanf("%d", &N);

    // Initialize the graph
    Graph g;
    initGraph(&g);

    // Read the indices u and v of the two nodes from the standard input
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;

    // Read the edges of the graph from the standard input and add them to the adjacency lists
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        addEdge(&g, a, b);
        addEdge(&g, b, a);
    }

    // Initialize the distance arrays d and e for depth-first search
    int d[MAX_N];
    int e[MAX_N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
        e[i] = INT_MAX;
    }

    // Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
    dfs(u, d, &g);
    dfs(v, e, &g);

    // Find the maximum difference between the distances of any node from u and v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Print the result: the maximum difference between the distances of any node from u and v
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    return 0;
}

Translate the above C code to Python and end with comment "