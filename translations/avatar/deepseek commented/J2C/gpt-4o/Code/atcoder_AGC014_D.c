#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// g is an array of pointers to arrays that will store the graph's adjacency list representation.
int *g[MAX_NODES];
int size[MAX_NODES]; // To keep track of the size of each adjacency list

// maxMatching function calculates the maximum matching in a tree structure.
int maxMatching(int v, int p) {
    int a = 0; // Number of matched pairs
    int o = 0; // Number of unmatched nodes
    for (int i = 0; i < size[v]; i++) {
        int w = g[v][i];
        if (w == p) continue; // Skip the parent node
        int r = maxMatching(w, v); // Recursively calculate matching for child nodes
        a += r / 2; // Add half of the matches from the child
        o += r % 2; // Count the unmatched nodes
    }
    return 2 * a + (o > 0 ? 1 : 0) + 1; // Return the total number of matches
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of nodes

    // Initialize the graph's adjacency list
    for (int i = 0; i < n; i++) {
        g[i] = (int *)malloc((n - 1) * sizeof(int)); // Allocate memory for adjacency list
        size[i] = 0; // Initialize size of each adjacency list
    }

    for (int i = 0; i < n - 1; i++) { // Read the edges and construct the graph
        int a, b;
        scanf("%d %d", &a, &b); // Read node a and b
        a--; b--; // Convert to 0-based index
        g[a][size[a]++] = b; // Add edge from a to b
        g[b][size[b]++] = a; // Add edge from b to a
    }

    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    printf("%s\n", (2 * m == n) ? "Second" : "First"); // Determine the winner and print the result

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i]);
    }

    return 0;
}

// <END-OF-CODE>
