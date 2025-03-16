#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

// Adjacency list to represent the graph
int g[MAXN][MAXN]; // Adjacency list
int size[MAXN]; // Size of each adjacency list
int visited[MAXN]; // Visited array for DFS

// Function to calculate the maximum matching in the graph
int maxMatching(int v, int p) {
    int a = 0; // Count of pairs in matching
    int o = 0; // Count of unmatched vertices

    // Iterate through all adjacent vertices of v
    for (int i = 0; i < size[v]; i++) {
        int w = g[v][i];
        // Skip the parent vertex to avoid cycles
        if (w == p) continue;

        // Recursively find the matching for the adjacent vertex
        int r = maxMatching(w, v);
        a += r / 2; // Update count of pairs
        o += r % 2; // Update count of unmatched vertices
    }

    // Return the total matching count
    return 2 * a + (o > 0 ? 1 : 0) + 1;
}

int main() {
    // Initialize input variables
    int n;
    
    // Read the number of vertices
    scanf("%d", &n);
    
    // Initialize the adjacency list for the graph
    for (int i = 0; i < n; i++) {
        size[i] = 0; // Initialize size of each adjacency list
    }

    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        g[a][size[a]++] = b; // Add edge to the graph
        g[b][size[b]++] = a; // Add edge to the graph (undirected)
    }

    // Calculate maximum matching starting from vertex 0
    int m = maxMatching(0, -1) / 2;

    // Determine the winner based on the matching result
    printf("%s\n", (2 * m == n) ? "Second" : "First");

    return 0;
}

// <END-OF-CODE>
