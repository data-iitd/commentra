#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Declare a graph represented as an adjacency list
int G[MAX_NODES][MAX_NODES];
int G_size[MAX_NODES]; // To keep track of the number of edges for each node
// Array to track visited nodes during DFS
int used[MAX_NODES];
// Array to store the Grundy values for each node
int grundy[MAX_NODES];

// Depth-First Search (DFS) function to compute Grundy values
void dfs(int v) {
    // Mark the current node as visited
    used[v] = 1;
    // Initialize the Grundy value for the current node
    grundy[v] = 0;

    // Iterate through all adjacent nodes
    for (int i = 0; i < G_size[v]; i++) {
        int neighbor = G[v][i];
        // If the adjacent node has not been visited
        if (!used[neighbor]) {
            // Recursively perform DFS on the adjacent node
            dfs(neighbor);
            // Update the Grundy value using the Grundy value of the child node
            grundy[v] ^= (grundy[neighbor] + 1);
        }
    }
}

int main() {
    // Read the number of nodes in the graph
    int N;
    scanf("%d", &N);

    // Read the edges of the graph
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // Convert to zero-based indexing
        x--; y--;
        // Add the edge to the adjacency list
        G[x][G_size[x]++] = y;
        G[y][G_size[y]++] = x;
    }

    // Start DFS from the root node (node 0)
    dfs(0);

    // Determine the winner based on the Grundy value of the root node
    if (grundy[0] != 0) {
        printf("Alice\n"); // Alice wins if Grundy value is non-zero
    } else {
        printf("Bob\n");   // Bob wins if Grundy value is zero
    }

    return 0;
}

// <END-OF-CODE>
