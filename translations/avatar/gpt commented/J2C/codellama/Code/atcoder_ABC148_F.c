#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100000

// Structure to represent an edge
typedef struct {
    int to;
    int next;
} Edge;

// Structure to represent a graph
typedef struct {
    int n;
    int m;
    Edge* edges;
} Graph;

// Function to create a graph
Graph* createGraph(int n, int m) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->m = m;
    g->edges = (Edge*)malloc(m * sizeof(Edge));
    return g;
}

// Function to add an edge to a graph
void addEdge(Graph* g, int from, int to) {
    g->edges[g->m].to = to;
    g->edges[g->m].next = g->edges[from].next;
    g->edges[from].next = g->m;
    g->m++;
}

// Function to perform DFS from a given node
void dfs(Graph* g, int u, int* d) {
    for (int i = g->edges[u].next; i < g->m; i = g->edges[i].next) {
        int nu = g->edges[i].to;
        if (d[nu] == INT_MAX) { // If the node has not been visited
            d[nu] = d[u] + 1; // Update the distance
            dfs(g, nu, d); // Recursively visit the next node
        }
    }
}

int main() {
    // Initialize the scanner to read input
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--; // Convert to zero-based index
    v--; // Convert to zero-based index
    
    // Create an adjacency list to represent the edges of the graph
    Graph* g = createGraph(N, N - 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        addEdge(g, a, b); // Add edge from a to b
        addEdge(g, b, a); // Add edge from b to a (undirected graph)
    }
    
    // Initialize distance array for the first node (u)
    int* d = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX; // Set initial distances to infinity
    }
    d[u] = 0; // Distance to itself is 0
    
    // Perform DFS from node u to calculate distances
    dfs(g, u, d);
    
    // Initialize distance array for the second node (v)
    int* e = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX; // Set initial distances to infinity
    }
    e[v] = 0; // Distance to itself is 0
    
    // Perform DFS from node v to calculate distances
    dfs(g, v, e);
    
    // Find the maximum distance from node u to any node that is closer to v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) { // Check if node i is closer to u than to v
            if (e[i] > q) { // Update q if the distance to v is greater
                q = e[i];
            }
        }
    }
    
    // Output the result based on the maximum distance found
    if (q <= 0) {
        printf("0\n"); // If no valid distance found, print 0
    } else {
        printf("%d\n", q - 1); // Print the maximum distance minus 1
    }
    
    // Free memory
    free(g->edges);
    free(g);
    free(d);
    free(e);
    
    return 0;
}

