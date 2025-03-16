#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    // Read the values of n (number of nodes) and m (number of edges) from input
    scanf("%d %d", &n, &m);

    // Create an array of health points for each node
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    // Create an adjacency list for the graph
    int **path = (int **)malloc((n + 1) * sizeof(int *));
    int *degree = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        path[i] = (int *)malloc(n * sizeof(int)); // Allocate maximum size
        degree[i] = 0; // Initialize degree of each node
    }

    // Read m edges from input and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a][degree[a]] = b; // Add edge from a to b
        degree[a]++;
        path[b][degree[b]] = a; // Add edge from b to a (undirected graph)
        degree[b]++;
    }

    // Initialize a counter for nodes that have no neighbors with equal or higher health points
    int c = 0;

    // Iterate through each node and its connected nodes
    for (int i = 1; i <= n; i++) {
        int f = 0; // Flag to check if any neighbor has equal or higher health points
        for (int j = 0; j < degree[i]; j++) {
            int neighbor = path[i][j];
            // Check if the current node's health is less than or equal to any of its neighbors
            if (h[i - 1] <= h[neighbor - 1]) { // h is 0-indexed, nodes are 1-indexed
                f = 1; // Set flag if a neighbor with equal or higher health is found
                break; // No need to check further neighbors
            }
        }
        // If no neighbors have equal or higher health points, increment the counter
        if (f == 0) {
            c++;
        }
    }

    // Print the count of nodes that have no neighbors with equal or higher health points
    printf("%d\n", c);

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(path[i]);
    }
    free(path);
    free(degree);
    free(h);

    return 0;
}

// <END-OF-CODE>
