#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

// Structure to represent a graph using adjacency list
typedef struct Graph {
    int **adjacencyList;
    int *degree;
} Graph;

// Function to create a graph with n vertices
Graph* createGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->adjacencyList = (int **)malloc((n + 1) * sizeof(int *));
    g->degree = (int *)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i <= n; i++) {
        g->adjacencyList[i] = (int *)malloc(MAX_VERTICES * sizeof(int));
    }
    
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph *g, int a, int b) {
    g->adjacencyList[a][g->degree[a]++] = b;
    g->adjacencyList[b][g->degree[b]++] = a;
}

// Depth First Search (DFS) function to traverse the graph
void dfs(Graph *g, bool *seen, int i, int *nodes, int *edges) {
    if (seen[i]) return;

    seen[i] = true;
    (*nodes)++;
    *edges += g->degree[i];

    for (int j = 0; j < g->degree[i]; j++) {
        dfs(g, seen, g->adjacencyList[i][j], nodes, edges);
    }
}

// Main function to solve the problem
bool solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return false; // End of input
    }

    Graph *g = createGraph(n);
    bool *seen = (bool *)calloc(n + 1, sizeof(bool));
    int ans = 0;

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(g, a, b);
    }

    // Traverse the graph using DFS for each unvisited vertex
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            int nodes = 0, edges = 0;
            dfs(g, seen, i, &nodes, &edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(g->adjacencyList[i]);
    }
    free(g->adjacencyList);
    free(g->degree);
    free(g);
    free(seen);

    return true;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {
        // Continue until there is no more input
    }
    return 0;
}

// <END-OF-CODE>
