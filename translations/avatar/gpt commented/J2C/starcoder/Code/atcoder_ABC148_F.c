#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the scanner to read input
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    
    // Create an adjacency list to represent the edges of the graph
    int** edges = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        edges[i] = (int*) malloc(N * sizeof(int));
    }
    
    // Read the edges and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a][b] = 1; // Add edge from a to b
        edges[b][a] = 1; // Add edge from b to a (undirected graph)
    }
    
    // Initialize distance array for the first node (u)
    int* d = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = 1000000000; // Set initial distances to infinity
    }
    d[u] = 0; // Distance to itself is 0
    
    // Perform DFS from node u to calculate distances
    dfs(u, d, edges);
    
    // Initialize distance array for the second node (v)
    int* e = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = 1000000000; // Set initial distances to infinity
    }
    e[v] = 0; // Distance to itself is 0
    
    // Perform DFS from node v to calculate distances
    dfs(v, e, edges);
    
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
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(d);
    free(e);
    
    return 0;
}

// Depth-first search (DFS) to calculate distances from a given node
void dfs(int u, int* d, int** edges) {
    for (int i = 0; i < N; i++) {
        if (edges[u][i] == 1 && d[i] == 1000000000) { // If the node has not been visited
            d[i] = d[u] + 1; // Update the distance
            dfs(i, d, edges); // Recursively visit the next node
        }
    }
}

