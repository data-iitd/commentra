#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id; // Unique identifier for the edge
    int to; // Destination node of the edge
} Edge;

typedef struct Node {
    Edge* edges; // Array of edges
    int edge_count; // Number of edges
} Node;

int n; // Number of nodes in the graph
Node* g; // Adjacency list representation of the graph
int* ans; // Array to store the answer for each edge

void dfs(int to, int color, int parents) {
    int k = 1; // Start coloring with color 1
    for (int i = 0; i < g[to].edge_count; i++) {
        Edge e = g[to].edges[i];
        // Skip the edge leading back to the parent node
        if (e.to == parents) continue;
        // If the current color is the same as the edge color, increment it
        if (k == color) k++;
        // Assign the color to the edge
        ans[e.id] = k;
        // Recursively call dfs for the connected node
        dfs(e.to, k, to);
        k++; // Increment color for the next edge
    }
}

int main() {
    // Create a Scanner object for input
    scanf("%d", &n);

    // Initialize the adjacency list for the graph
    g = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        g[i].edges = (Edge*)malloc((n - 1) * sizeof(Edge)); // Allocate space for edges
        g[i].edge_count = 0; // Initialize edge count
    }

    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Adjust for 0-based indexing
        b--; // Adjust for 0-based indexing
        // Add the edge to both endpoints' adjacency lists
        g[a].edges[g[a].edge_count++] = (Edge){i, b};
        g[b].edges[g[b].edge_count++] = (Edge){i, a};
    }

    // Initialize the answer array to store results for each edge
    ans = (int*)malloc((n - 1) * sizeof(int));

    // Perform a depth-first search starting from node 0
    dfs(0, -1, -1);

    // Find the maximum value in the ans array
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] > max) {
            max = ans[i];
        }
    }

    // Output the maximum value found
    printf("%d\n", max);

    // Output the results for each edge
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i].edges);
    }
    free(g);
    free(ans);

    return 0;
}

// <END-OF-CODE>
