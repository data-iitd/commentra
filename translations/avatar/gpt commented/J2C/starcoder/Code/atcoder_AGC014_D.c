#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adjacency list to represent the graph
static int **g; 

// Function to calculate the maximum matching in the graph
static int maxMatching(int v, int p) {
    int a = 0; // Count of pairs in matching
    int o = 0; // Count of unmatched vertices
    
    // Iterate through all adjacent vertices of v
    for (int w = 0; w < g[v][0]; ++w) {
        // Skip the parent vertex to avoid cycles
        if (g[v][w] == p) continue; 
        
        // Recursively find the matching for the adjacent vertex
        int r = maxMatching(g[v][w], v); 
        a += r / 2; // Update count of pairs
        o += r % 2; // Update count of unmatched vertices
    }
    
    // Return the total matching count
    return 2 * a + (o < 1? 1 : 0) + 1; 
} 

int main() {
    // Read the number of vertices
    int n; 
    scanf("%d", &n); 
    
    // Initialize the adjacency list for the graph
    g = (int **) malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; ++i) {
        g[i] = (int *) malloc(n * sizeof(int)); 
        g[i][0] = 0; 
    }
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; ++i) {
        int a, b; 
        scanf("%d %d", &a, &b); 
        g[a - 1][g[a - 1][0]++] = b - 1; 
        g[b - 1][g[b - 1][0]++] = a - 1; 
    }
    
    // Calculate maximum matching starting from vertex 0
    int m = maxMatching(0, -1) / 2; 
    
    // Determine the winner based on the matching result
    printf("%s\n", 2 * m == n? "Second" : "First"); 
    
    // Free the adjacency list
    for (int i = 0; i < n; ++i) {
        free(g[i]); 
    }
    free(g); 
    
    return 0; 
}

