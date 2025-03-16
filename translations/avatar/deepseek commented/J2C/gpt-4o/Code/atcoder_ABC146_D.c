#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Node {
    Edge* edges;
    int edge_count;
} Node;

int n;
Node* g; // Graph as an adjacency list
int* ans; // Answer array to store edge colors

void dfs(int to, int color, int parent) { // Define the DFS function
    int k = 1; // Initialize the color counter
    for (int i = 0; i < g[to].edge_count; i++) { // Iterate through the adjacency list of the current node
        Edge e = g[to].edges[i];
        if (e.to == parent) continue; // Skip if the neighbor is the parent
        if (k == color) k++; // Ensure the color is not the same as the parent's color
        ans[e.id] = k; // Assign the color to the edge
        dfs(e.to, k, to); // Recursively call DFS for the neighbor
        k++; // Increment the color counter for the next edge
    }
}

int main() {
    scanf("%d", &n); // Read the number of nodes
    g = (Node*)malloc(n * sizeof(Node)); // Initialize the graph
    for (int i = 0; i < n; i++) {
        g[i].edges = (Edge*)malloc((n - 1) * sizeof(Edge)); // Allocate memory for edges
        g[i].edge_count = 0; // Initialize each node's edge count
    }
    
    ans = (int*)malloc((n - 1) * sizeof(int)); // Initialize the answer array

    for (int i = 0; i < n - 1; i++) { // Read and populate the graph
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        g[a].edges[g[a].edge_count++] = (Edge){i, b}; // Add edge from a to b
        g[b].edges[g[b].edge_count++] = (Edge){i, a}; // Add edge from b to a
    }

    dfs(0, -1, -1); // Call DFS with root node 0, initial color -1, and parent -1

    int max = 0; // Initialize max to find the maximum color used
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] > max) {
            max = ans[i]; // Find the maximum color used
        }
    }
    
    printf("%d\n", max); // Print the maximum color used
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]); // Print the colors assigned to each edge
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i].edges); // Free edges for each node
    }
    free(g); // Free the graph
    free(ans); // Free the answer array

    return 0;
}

// <END-OF-CODE>
