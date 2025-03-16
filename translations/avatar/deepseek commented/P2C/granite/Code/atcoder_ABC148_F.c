
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to read an integer from standard input
int inp() {
    int res;
    scanf("%d", &res);
    return res;
}

// Function to read a list of integers from standard input
int* inpl(int n) {
    int* res = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        res[i] = inp();
    }
    return res;
}

int main() {
    // Read the number of nodes, starting node for Ta, and starting node for Ao
    int n = inp(), ta = inp() - 1, ao = inp() - 1;

    // Initialize the graph as a 2D array of integers, each representing adjacency list of a node
    int** g = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        g[i] = (int*)malloc(sizeof(int) * (n - 1));
    }

    // Read edges to construct the graph
    for (int i = 0; i < n - 1; i++) {
        int a = inp() - 1, b = inp() - 1;
        g[a][i] = b;  // Store the zero-based index of the neighbor
        g[b][i] = a;  // Store the zero-based index of the neighbor
    }

    // Initialize distance arrays to INT_MAX, will be populated during DFS
    int* ta_dist = (int*)malloc(sizeof(int) * n);
    int* ao_dist = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ta_dist[i] = ao_dist[i] = INT_MAX;
    }
    ta_dist[ta] = 0;  // Distance from Ta to Ta is 0
    ao_dist[ao] = 0;  // Distance from Ao to Ao is 0

    // Depth-First Search (DFS) function to compute distances from Ta
    void ta_dfs(int node, int* dist, int** g, int n) {
        for (int i = 0; i < n - 1; i++) {
            int v = g[node][i];
            if (dist[v]!= INT_MAX) {  // If already visited, skip
                continue;
            }
            dist[v] = dist[node] + 1;  // Update distance
            ta_dfs(v, dist, g, n);  // Recursively visit neighbors
        }
    }

    // Depth-First Search (DFS) function to compute distances from Ao
    void ao_dfs(int node, int* dist, int** g, int n) {
        for (int i = 0; i < n - 1; i++) {
            int v = g[node][i];
            if (dist[v]!= INT_MAX) {  // If already visited, skip
                continue;
            }
            dist[v] = dist[node] + 1;  // Update distance
            ao_dfs(v, dist, g, n);  // Recursively visit neighbors
        }
    }

    // Start DFS from Ao to compute distances
    ao_dfs(ao, ao_dist, g, n);

    // Start DFS from Ta to compute distances
    ta_dfs(ta, ta_dist, g, n);

    // Initialize result variable
    int res = 0;

    // Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) {  // Skip if Ta's distance is greater
            continue;
        }
        res = fmax(res, ao_dist[i]);  // Update result with the maximum distance
    }

    // Print the result, which is the maximum distance minus one
    printf("%d\n", res - 1);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(g[i]);
    }
    free(g);
    free(ta_dist);
    free(ao_dist);

    return 0;
}
