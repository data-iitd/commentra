#include <stdio.h>
#include <stdlib.h>

// Number of nodes in the graph
int n; 
// Adjacency list representation of the graph, where each node points to a list of edges
int **g; 
// Array to store the answer for each edge
int *ans; 

// Class to represent an edge in the graph
typedef struct Edge { 
    // Constructor to initialize edge with id and destination
    Edge(int id, int to) { 
        this->id = id; 
        this->to = to; 
    } 
    int id; // Unique identifier for the edge
    int to; // Destination node of the edge
} Edge;

// Depth-first search function to traverse the graph and assign colors to edges
void dfs(int to, int color, int parents) { 
    int k = 1; // Start coloring with color 1
    for (int i = 0; i < g[to].size(); i++) { 
        // Skip the edge leading back to the parent node
        if (g[to][i].to == parents) continue; 
        // If the current color is the same as the edge color, increment it
        if (k == color) k++; 
        // Assign the color to the edge
        ans[g[to][i].id] = k; 
        // Recursively call dfs for the connected node
        dfs(g[to][i].to, k, to); 
        k++; // Increment color for the next edge
    } 
} 

int main() { 
    // Create a Scanner object for input
    scanf("%d", &n); 
    
    // Initialize the adjacency list for the graph
    g = (int**)malloc(n * sizeof(int*)); 
    for (int i = 0; i < n; i++) { 
        g[i] = (int*)malloc(n * sizeof(int)); 
    } 
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; i++) { 
        // Read the two endpoints of the edge, adjusting for 0-based indexing
        int a, b; 
        scanf("%d", &a); 
        scanf("%d", &b); 
        // Add the edge to both endpoints' adjacency lists
        g[a - 1][i] = b - 1; 
        g[b - 1][i] = a - 1; 
    } 
    
    // Initialize the answer array to store results for each edge
    ans = (int*)malloc((n - 1) * sizeof(int)); 
    
    // Perform a depth-first search starting from node 0
    dfs(0, -1, -1); 
    
    // Find the maximum value in the ans array
    int max = 0; 
    for (int i = 0; i < n - 1; i++) { 
        max = max > ans[i]? max : ans[i]; 
    } 
    
    // Output the maximum value found
    printf("%d\n", max); 
    
    // Output the results for each edge
    for (int i = 0; i < n - 1; i++) { 
        printf("%d\n", ans[i]); 
    } 
    
    // Free memory
    for (int i = 0; i < n; i++) { 
        free(g[i]); 
    } 
    free(g); 
    free(ans); 
    
    return 0; 
}

