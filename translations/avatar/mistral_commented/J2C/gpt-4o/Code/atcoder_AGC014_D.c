#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct {
    int *data; // Array to hold the neighbors
    int size;  // Number of neighbors
    int capacity; // Capacity of the array
} Graph;

// Function to initialize a graph
void initGraph(Graph *g, int capacity) {
    g->data = (int *)malloc(capacity * sizeof(int));
    g->size = 0;
    g->capacity = capacity;
}

// Function to add an edge to the graph
void addEdge(Graph *g, int neighbor) {
    if (g->size >= g->capacity) {
        g->capacity *= 2;
        g->data = (int *)realloc(g->data, g->capacity * sizeof(int));
    }
    g->data[g->size++] = neighbor;
}

// Function to find the maximum number of edges that can be matched in a bipartite graph
int maxMatching(Graph *g, int v, int p, int n) {
    int a = 0; // Number of edges matched from the neighboring vertices of 'v'
    int o = 0; // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    // Iterating through all the neighbors of 'v'
    for (int i = 0; i < g[v].size; i++) {
        int w = g[v].data[i];
        if (w == p) continue; // Skip if the neighbor is 'p' (self-loop)

        // Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
        int r = maxMatching(g, w, v, n);
        a += r / 2;
        o += r % 2;
    }

    // Returning the result based on the parity of 'o'
    return 2 * a + (o > 0 ? 1 : 0);
}

int main() {
    // Reading the number of vertices in the graph
    int n;
    scanf("%d", &n);

    // Initializing the graph as an array of Graph structures
    Graph *g = (Graph *)malloc(n * sizeof(Graph));
    for (int i = 0; i < n; i++) {
        initGraph(&g[i], 2); // Initialize with a capacity of 2
    }

    // Reading the edges and adding them to the graph
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        addEdge(&g[a], b); // Adding the edge from 'a' to 'b'
        addEdge(&g[b], a); // Adding the edge from 'b' to 'a'
    }

    // Finding the maximum number of edges that can be matched in the graph
    int maxMatchingCount = maxMatching(g, 0, -1, n) / 2;

    // Printing the result based on whether all vertices have even degree or not
    printf("%s\n", 2 * maxMatchingCount == n ? "Second" : "First");

    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i].data);
    }
    free(g);

    return 0;
}

// <END-OF-CODE>
