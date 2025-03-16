#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables for the adjacency list representation of the graph
int **e;
int n, m;

// Function to print the edges of the graph
void printEdge(int **e) {
    // Iterate through each node in the graph
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i); // Print the node number
        // Print all adjacent nodes (edges) for the current node
        for (int j = 0; j < n; j++) {
            if (e[i][j] != 0) {
                printf("%d ", e[i][j]);
            }
        }
        printf("\n"); // Move to the next line after printing all edges for the current node
    }
}

// Depth-first search (DFS) function to explore the graph
int dfs(int v, bool *visited) {
    // Check if all nodes have been visited
    bool comp = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = false; // If any node is not visited, set comp to false
        }
    }

    // If all nodes have been visited, return 1 (indicating a complete component)
    if (comp) {
        return 1;
    }

    int count = 0; // Initialize count of connected nodes
    // Explore all neighbors of the current node
    for (int ne = 1; ne <= n; ne++) {
        if (e[v][ne] != 0) { // Check if there is an edge
            // Skip already visited nodes
            if (visited[ne]) {
                continue;
            }
            visited[ne] = true; // Mark the neighbor as visited
            // Recursively call DFS for the neighbor and accumulate the count
            int rst = dfs(ne, visited);
            count += rst; // Increment the count with the result from the DFS call
            visited[ne] = false; // Backtrack: unmark the neighbor as visited
        }
    }
    return count; // Return the total count of connected nodes
}

int main() {
    // Read the number of nodes and edges from input
    scanf("%d %d", &n, &m);

    // Initialize the adjacency list for the graph
    e = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        e[i] = (int *)calloc(n + 1, sizeof(int)); // Create an empty array for each node
    }

    // Read the edges and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read each edge
        e[a][b] = 1; // Add the edge to the adjacency list
        e[b][a] = 1; // Since the graph is undirected, add both directions
    }

    // Uncomment to print the edges of the graph
    // printEdge(e);

    // Initialize the visited array to keep track of visited nodes
    bool *visited = (bool *)calloc(n + 1, sizeof(bool));
    visited[1] = true; // Mark the starting node (node 1) as visited
    int count = dfs(1, visited); // Perform DFS starting from node 1
    printf("%d\n", count); // Print the count of connected nodes

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(e[i]);
    }
    free(e);
    free(visited);

    return 0;
}

// <END-OF-CODE>
