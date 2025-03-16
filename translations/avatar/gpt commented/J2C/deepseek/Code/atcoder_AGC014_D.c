#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

// Adjacency list to represent the graph
int g[MAX_N][MAX_N];
int visited[MAX_N];
int match[MAX_N];

// Function to calculate the maximum matching in the graph
int maxMatching(int v, int p, int n) {
    int a = 0; // Count of pairs in matching
    int o = 0; // Count of unmatched vertices
    
    // Iterate through all adjacent vertices of v
    for (int w = 0; w < n; ++w) {
        if (g[v][w] == 0 || w == p) continue; 
        
        // Recursively find the matching for the adjacent vertex
        int r = maxMatching(w, v, n); 
        a += r / 2; // Update count of pairs
        o += r % 2; // Update count of unmatched vertices
    }
    
    // Return the total matching count
    return 2 * a + (o > 0 ? 1 : 0) + 1; 
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Initialize the adjacency matrix for the graph
    memset(g, 0, sizeof(g));
    
    // Read edges and populate the adjacency matrix
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a - 1][b - 1] = 1; // Add edge to the graph
        g[b - 1][a - 1] = 1; // Add edge to the graph (undirected)
    }
    
    // Calculate maximum matching starting from vertex 0
    int m = maxMatching(0, -1, n) / 2;
    
    // Determine the winner based on the matching result
    printf("%s\n", 2 * m == n ? "Second" : "First");
    
    return 0;
}

