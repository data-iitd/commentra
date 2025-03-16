#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

// g is a static array of ArrayLists that will store the graph's adjacency list representation.
static int g[MAX_NODES][MAX_NODES];

// maxMatching method calculates the maximum matching in a tree structure.
int maxMatching(int v, int p) {
    int a = 0; // Number of matched pairs
    int o = 0; // Number of unmatched nodes
    for (int w = 0; w < MAX_NODES; ++w) {
        if (g[v][w] == 0 || w == p) continue; // Skip the parent node
        int r = maxMatching(w, v); // Recursively calculate matching for child nodes
        a += r / 2; // Add half of the matches from the child
        o += r % 2; // Count the unmatched nodes
    }
    return 2 * a + (o < 2 ? 1 : 0); // Return the total number of matches
}

int main() {
    int n; // Number of nodes
    scanf("%d", &n); // Read the number of nodes
    memset(g, 0, sizeof(g)); // Initialize the graph's adjacency list
    for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
        int a, b; // Read node a and b
        scanf("%d %d", &a, &b);
        g[a - 1][b - 1] = 1; // Add edge from a to b
        g[b - 1][a - 1] = 1; // Add edge from b to a
    }
    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    printf("%s\n", m == n / 2 ? "Second" : "First"); // Determine the winner and print the result
    return 0;
}

