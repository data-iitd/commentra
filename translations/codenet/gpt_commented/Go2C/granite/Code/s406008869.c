
#include <stdio.h>
#include <stdbool.h>

// Declare a global variable for the adjacency list representation of the graph
int **e;
// Declare variables for the number of nodes (n) and edges (m)
int n, m;

// Function to print the edges of the graph
void printEdge(int **e) {
    // Iterate through each node in the graph
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i); // Print the node number
        // Print all adjacent nodes (edges) for the current node
        for (int j = 0; j < e[i][0]; j++) {
            printf("%d ", e[i][j+1]);
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
    for (int j = 0; j < e[v][0]; j++) {
        int ne = e[v][j+1];
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
    return count; // Return the total count of connected nodes
}

int main() {
    // Read the number of nodes and edges from input
    scanf("%d %d", &n, &m);

    // Initialize the adjacency list for the graph
    e = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        e[i] = (int *)malloc(sizeof(int) * (m + 1));
        e[i][0] = 0; // Initialize the count of edges for each node to 0
    }
    // Read the edges and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read each edge
        e[a][0]++; // Increment the count of edges for node a
        e[b][0]++; // Increment the count of edges for node b
        e[a][e[a][0]] = b; // Add the edge to the adjacency list for node a
        e[b][e[b][0]] = a; // Since the graph is undirected, add both directions for node b
    }
    // Uncomment to print the edges of the graph
    // printEdge(e);

    // Initialize the visited array to keep track of visited nodes
    bool *visited = (bool *)malloc(sizeof(bool) * (n + 1));
    for (int i = 1; i <= n; i++) {
        visited[i] = false; // Initialize all nodes as unvisited
    }
    visited[1] = true; // Mark the starting node (node 1) as visited
    int count = dfs(1, visited); // Perform DFS starting from node 1
    printf("%d\n", count); // Print the count of connected nodes

    // Free the memory allocated for the adjacency list and visited array
    for (int i = 1; i <= n; i++) {
        free(e[i]);
    }
    free(e);
    free(visited);

    return 0;
}
