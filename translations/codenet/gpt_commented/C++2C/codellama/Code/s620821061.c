#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 520

typedef struct {
    int G[2*V][2*V]; // Adjacency list for the bipartite graph
    int match[2*V];  // Array to store matches for vertices
    int used[2*V];   // Array to track visited vertices during DFS
} BitMatching;

void init(BitMatching *bm) {
    for (int i = 0; i < 2*V; i++) {
        bm->G[i][0] = 0;
    }
}

void add(BitMatching *bm, int a, int b) {
    bm->G[a][bm->G[a][0] + 1] = b + V; // Connect a to b in the second set
    bm->G[b + V][bm->G[b + V][0] + 1] = a; // Connect b to a in the first set
}

int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1; // Mark the current vertex as visited
    for (int i = 1; i <= bm->G[v][0]; i++) {
        int u = bm->G[v][i], w = bm->match[u]; // Get the matched vertex for u
        // If u is unmatched or we can find an augmenting path
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) {
            bm->match[v] = u; // Match v with u
            bm->match[u] = v; // Match u with v
            return 1;  // Found a match
        }
    }
    return 0; // No match found
}

int exec(BitMatching *bm) {
    int res = 0; // Result variable to count matches
    memset(bm->match, -1, sizeof(bm->match)); // Initialize matches to -1 (unmatched)
    for (int v = 0; v < V; v++) {
        if (bm->match[v] < 0) { // If vertex v is unmatched
            memset(bm->used, 0, sizeof(bm->used)); // Reset visited array
            if (dfs(bm, v)) { // Try to find a match for v
                res++; // Increment the result if a match is found
            }
        }
    }
    return res; // Return the total number of matches
}

int gcd(int a, int b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive case: GCD of b and a mod b
}

int main() {
    while (1) {
        int n, m; // Number of elements in two sets
        scanf("%d %d", &n, &m); // Read the sizes of the two sets
        if (!n) break; // Exit if n is 0 (no more input)

        BitMatching bm; // Create an instance of BitMatching
        init(&bm); // Initialize the BitMatching instance
        int a[n], b[m]; // Arrays to hold the elements of the two sets
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); // Read elements of the first set
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]); // Read elements of the second set
        }

        // Build the bipartite graph based on the GCD condition
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j]) != 1) { // If GCD is not 1, add an edge
                    add(&bm, i, j);
                }
            }
        }
        
        // Execute the matching algorithm and print the result
        printf("%d\n", exec(&bm));
    }
    return 0; // End of the program
}

