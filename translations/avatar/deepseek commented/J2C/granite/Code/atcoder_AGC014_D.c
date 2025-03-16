
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// g is a static array of ArrayLists that will store the graph's adjacency list representation.
ArrayList(int) *g;

// maxMatching method calculates the maximum matching in a tree structure.
int maxMatching(int v, int p) {
    int a = 0; // Number of matched pairs
    int o = 0; // Number of unmatched nodes
    for (int i = 0; i < g[v].size; ++i) {
        int w = g[v].arr[i];
        if (w == p) continue; // Skip the parent node
        int r = maxMatching(w, v); // Recursively calculate matching for child nodes
        a += r / 2; // Add half of the matches from the child
        o += r % 2; // Count the unmatched nodes
    }
    return 2 * a + Math.min(1, o) + 1; // Return the total number of matches
}

int main() {
    int n; // Read the number of nodes
    scanf("%d", &n);
    g = (ArrayList(int) *)malloc(n * sizeof(ArrayList(int))); // Initialize the graph's adjacency list
    for (int i = 0; i < n; ++i) {
        g[i] = newArrayList(int); // Initialize each node's adjacency list
    }
    for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        add(g[a], b); // Add edge from a to b
        add(g[b], a); // Add edge from b to a
    }
    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    printf("%s\n", 2 * m == n? "Second" : "First"); // Determine the winner and print the result
    for (int i = 0; i < n; ++i) {
        freeArrayList(g[i]); // Free the memory allocated for each node's adjacency list
    }
    free(g); // Free the memory allocated for the graph's adjacency list
    return 0;
}

