
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes
#define MAX_N 100000

// Define the maximum recursion depth
#define MAX_RECURSION_DEPTH 1000000

// Define the structure to represent the graph (tree) connections
typedef struct {
    int *links;
    int *height_from_leaf;
    int *cut_count;
} Graph;

// Function to initialize the graph structure
void init_graph(Graph *g, int n) {
    g->links = (int *)malloc(sizeof(int) * n);
    g->height_from_leaf = (int *)malloc(sizeof(int) * n);
    g->cut_count = (int *)malloc(sizeof(int) * n);
}

// Function to free the memory allocated for the graph structure
void free_graph(Graph *g) {
    free(g->links);
    free(g->height_from_leaf);
    free(g->cut_count);
}

// Function to perform DFS on the graph
void dfs(Graph *g, int n, int k, int v, int p) {
    // Initialize height from the leaf node and cut count
    g->height_from_leaf[v] = 0;
    g->cut_count[v] = 0;
    
    // Iterate through all connected nodes (children) of the current node
    for (int i = 0; i < n; i++) {
        // Skip if the child node is 0 (indicating no further connections)
        if (g->links[v] == 0) {
            continue;
        }
        
        // Recursively perform DFS on the child node and get its height and cut count
        dfs(g, n, k, g->links[v], v);
        
        // Update the maximum height from the leaf node
        g->height_from_leaf[v] = g->height_from_leaf[v] > g->height_from_leaf[g->links[v]]? g->height_from_leaf[v] : g->height_from_leaf[g->links[v]];
        
        // Accumulate the cut count from the child nodes
        g->cut_count[v] += g->cut_count[g->links[v]];
    }
    
    // Increment the height from the leaf node as we return to the parent
    g->height_from_leaf[v] += 1;
    
    // Check if the current height matches k and we are not at the root node
    if (p!= 0 && g->height_from_leaf[v] == k) {
        // Reset height from leaf to 0 and increment cut count
        g->height_from_leaf[v] = 0;
        g->cut_count[v] += 1;
    }
}

int main() {
    // Read input values for n (number of nodes), k (target height), and the rest of the connections
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Create a graph structure to represent the connections
    Graph g;
    init_graph(&g, n);
    
    // Populate the links based on the input connections
    for (int i = 0; i < n; i++) {
        scanf("%d", &g.links[i]);
        g.links[i]--;  // Adjust for 0-based indexing
    }
    
    // Perform DFS starting from the root node (0) and get the total cuts
    dfs(&g, n, k, 0, 0);
    
    // If the first node is not the root, increment the answer
    if (g.links[0]!= 1) {
        g.cut_count[0] += 1;
    }
    
    // Print the final answer (total cuts)
    printf("%d\n", g.cut_count[0]);
    
    // Free the memory allocated for the graph structure
    free_graph(&g);
    
    return 0;
}

Translate the above C code to Rust and end with comment "