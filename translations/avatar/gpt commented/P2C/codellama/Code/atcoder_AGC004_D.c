
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000
#define MAX_HEIGHT 100000

// Structure to represent a node in the graph
typedef struct {
    int height_from_leaf;
    int cut_count;
} Node;

// Structure to represent the graph
typedef struct {
    Node nodes[MAX_NODES];
    int n;
    int k;
} Graph;

// Function to perform DFS on the graph
void dfs(Graph *graph, int v, int p) {
    // Initialize height from the leaf node and cut count
    graph->nodes[v].height_from_leaf = 0;
    graph->nodes[v].cut_count = 0;
    
    // Iterate through all connected nodes (children) of the current node
    for (int u = 0; u < graph->n; u++) {
        // Skip if the child node is 0 (indicating no further connections)
        if (graph->nodes[v].height_from_leaf == 0) {
            continue;
        }
        
        // Recursively perform DFS on the child node and get its height and cut count
        dfs(graph, u, v);
        
        // Update the maximum height from the leaf node
        graph->nodes[v].height_from_leaf = max(graph->nodes[v].height_from_leaf, graph->nodes[u].height_from_leaf);
        
        // Accumulate the cut count from the child nodes
        graph->nodes[v].cut_count += graph->nodes[u].cut_count;
    }
    
    // Increment the height from the leaf node as we return to the parent
    graph->nodes[v].height_from_leaf += 1;
    
    // Check if the current height matches k and we are not at the root node
    if (p != 0 && graph->nodes[v].height_from_leaf == graph->k) {
        // Reset height from leaf to 0 and increment cut count
        graph->nodes[v].height_from_leaf = 0;
        graph->nodes[v].cut_count += 1;
    }
}

int main() {
    // Read input values for n (number of nodes), k (target height), and the rest of the connections
    int n, k, *aaa;
    scanf("%d %d", &n, &k);
    aaa = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aaa[i]);
    }
    
    // Create a list of sets to represent the graph (tree) connections
    int **links = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        links[i] = (int *)malloc(sizeof(int) * n);
        memset(links[i], 0, sizeof(int) * n);
    }
    
    // Populate the links based on the input connections
    for (int i = 0; i < n; i++) {
        links[aaa[i] - 1][i] = 1;
    }
    
    // Create a graph structure to store the nodes and their heights
    Graph graph;
    graph.n = n;
    graph.k = k;
    
    // Perform DFS starting from the root node (0) and get the total cuts
    dfs(&graph, 0, 0);
    
    // If the first node is not the root, increment the answer
    if (aaa[0] != 1) {
        graph.nodes[0].cut_count += 1;
    }
    
    // Print the final answer (total cuts)
    printf("%d\n", graph.nodes[0].cut_count);
    
    // Free memory
    free(aaa);
    for (int i = 0; i < n; i++) {
        free(links[i]);
    }
    free(links);
    
    return 0;
}

