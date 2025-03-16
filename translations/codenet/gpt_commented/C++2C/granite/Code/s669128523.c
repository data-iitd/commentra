
/* Depth First Search (DFS) implementation
   This implementation does not use recursion stack.
*/

#include <stdio.h>

// Define constants for maximum number of nodes and colors
#define N 100 // Maximum number of nodes
#define WHITE 0 // Color for unvisited nodes
#define GRAY 1 // Color for nodes being visited
#define BLACK 2 // Color for fully visited nodes

// Adjacency matrix to represent the graph, number of nodes, and arrays for DFS
int M[N][N], n; // M is the adjacency matrix, n is the number of nodes
int color[N], d[N], f[N], tt; // Arrays to store colors, discovery times, finish times, and a time counter

// Function to visit nodes in DFS
void dfs_visit(int u) {
    int v;
    // Mark the current node as being visited
    color[u] = GRAY;
    // Set the discovery time for the current node
    d[u] = ++tt;

    // Explore all adjacent nodes
    for (v = 0; v < n; v++) {
        // Skip if there is no edge from u to v
        if (M[u][v] == 0)
            continue;
        // If the adjacent node is unvisited, recursively visit it
        if (color[v] == WHITE) {
            dfs_visit(v);
        }
    }
    // Mark the current node as fully visited
    color[u] = BLACK;
    // Set the finish time for the current node
    f[u] = ++tt;
}

// Function to perform DFS on the graph
void dfs() {
    int u;
    // Initialize all nodes as unvisited
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }
    tt = 0; // Reset the time counter

    // Perform DFS for each unvisited node
    for (u = 0; u < n; u++) {
        if (color[u] == WHITE)
            dfs_visit(u);
    }

    // Output the discovery and finish times for each node
    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", i + 1, d[i], f[i]);
}

int main() {
    int k, u, v;
    // Read the number of nodes
    scanf("%d", &n);
    // Initialize the adjacency matrix to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
    }
    // Read the graph edges
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &k); // Read the node and number of edges
        u--; // Convert to zero-based index
        for (int j = 0; j < k; j++) {
            scanf("%d", &v); // Read each adjacent node
            v--; // Convert to zero-based index
            M[u][v] = 1; // Mark the edge in the adjacency matrix
        }
    }

    // Perform DFS on the graph
    dfs();    

    return 0; // End of the program
}
