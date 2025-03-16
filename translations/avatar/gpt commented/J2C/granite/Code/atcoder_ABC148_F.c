
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dfs(int u, int *d, int **edges, int N) {
    for (int i = 0; i < N; i++) {
        if (d[i] == INT_MAX) { // If the node has not been visited
            d[i] = d[u] + 1; // Update the distance
            dfs(i, d, edges, N); // Recursively visit the next node
        }
    }
}

int main() {
    // Initialize the scanner to read input
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Read the number of nodes (N) and the two specific nodes (u and v)
    int N, u, v;
    fscanf(fp, "%d %d %d", &N, &u, &v);
    u--; // Convert to zero-based index
    v--; // Convert to zero-based index
    
    // Create an adjacency list to represent the edges of the graph
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            edges[i][j] = 0; // Initialize all edges as 0
        }
    }
    
    // Read the edges and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fscanf(fp, "%d %d", &a, &b);
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        edges[a][b] = 1; // Add edge from a to b
        edges[b][a] = 1; // Add edge from b to a (undirected graph)
    }
    
    // Initialize distance array for the first node (u)
    int *d = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX; // Set initial distances to infinity
    }
    d[u] = 0; // Distance to itself is 0
    
    // Perform DFS from node u to calculate distances
    dfs(u, d, edges, N);
    
    // Initialize distance array for the second node (v)
    int *e = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX; // Set initial distances to infinity
    }
    e[v] = 0; // Distance to itself is 0
    
    // Perform DFS from node v to calculate distances
    dfs(v, e, edges, N);
    
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
    
    fclose(fp);
    
    return 0;
}
