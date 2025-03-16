#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000  // Define a maximum number of nodes
#define MAX_COLORS 100000  // Define a maximum number of colors
#define MOD 1000000007  // Define a modulus for the result to prevent overflow

// Define a graph structure to store adjacency lists
struct Graph {
    int *adj;  // Adjacency list
    int n;  // Number of nodes
    int m;  // Number of edges
};

// Define a function to perform depth-first search (DFS) and count valid colorings
int dfs(int fro, int to, int f, struct Graph *g) {
    int caseNum = f;  // Initialize case number with the current color
    int colorNum = g->n - 1;  // Determine the number of available colors for the next node
    
    // Iterate through all adjacent nodes in the graph
    for (int i = 0; i < g->m; i++) {
        int u = g->adj[i];  // Read each edge
        if (u == to) {  // Skip the node we came from to avoid cycles
            continue;
        }
        int pat = dfs(u, fro, colorNum, g);  // Recursively call DFS for the adjacent node
        if (pat == 0) {  // If no valid coloring is found, break out
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;  // Update the case number with the valid patterns found
        colorNum--;  // Decrease the available colors for the next node
    }
    
    return caseNum;  // Return the total valid colorings found
}

int main() {
    int N, K;  // Define variables to store the number of nodes and colors
    scanf("%d %d", &N, &K);  // Read the number of nodes and colors
    
    // Build the graph by reading N-1 edges
    struct Graph g;
    g.n = N;
    g.m = N - 1;
    g.adj = (int *)malloc(g.m * sizeof(int));
    for (int i = 0; i < g.m; i++) {
        int a, b;  // Read each edge
        scanf("%d %d", &a, &b);
        g.adj[i] = b - 1;  // Add edge from a to b (0-indexed)
    }
    
    // Start the DFS from the root node (0) with no parent (-1) and K colors
    int ans = dfs(0, -1, K, &g);
    
    // Print the final answer which is the number of valid colorings
    printf("%d\n", ans);
    
    return 0;
}

