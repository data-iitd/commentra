
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// BitMatching struct for finding maximum matching in a bipartite graph
typedef struct {
    int V; // Number of vertices
    int *G; // Adjacency list for the bipartite graph
    int *match; // Array to store matches for vertices
    int *used; // Array to track visited vertices during DFS
} BitMatching;

// Initializes the graph by clearing the adjacency list
void init(BitMatching *bm) {
    int i;
    for (i = 0; i < 2 * bm->V; i++) {
        bm->G[i] = -1;
    }
}

// Adds an edge between vertex a and vertex b in the bipartite graph
void add(BitMatching *bm, int a, int b) {
    int p = bm->G[a];
    bm->G[a] = b + bm->V;
    bm->G[b + bm->V] = p;
}

// Depth-First Search to find an augmenting path
int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1; // Mark the current vertex as visited
    for (int u = bm->G[v]; u >= 0; u = bm->G[u]) {
        int w = bm->match[u]; // Get the matched vertex for u
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) {
            bm->match[v] = u; // Match v with u
            bm->match[u] = v; // Match u with v
            return 1; // Found a match
        }
    }
    return 0; // No match found
}

// Executes the matching algorithm and returns the size of the maximum matching
int exec(BitMatching *bm) {
    int res = 0; // Result variable to count matches
    int i;
    for (i = 0; i < bm->V; i++) {
        if (bm->match[i] < 0) { // If vertex v is unmatched
            for (i = 0; i < bm->V; i++) {
                bm->used[i] = 0; // Reset visited array
            }
            if (dfs(bm, i)) { // Try to find a match for v
                res++; // Increment the result if a match is found
            }
        }
    }
    return res; // Return the total number of matches
}

// Function to compute the greatest common divisor (GCD) of two numbers
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive case: GCD of b and a mod b
}

int main() {
    while (true) {
        int n, m; // Number of elements in two sets
        scanf("%d %d", &n, &m); // Read the sizes of the two sets
        if (!n) break; // Exit if n is 0 (no more input)

        BitMatching *bm = (BitMatching *)malloc(sizeof(BitMatching)); // Allocate memory for BitMatching instance
        bm->V = n + m; // Set the number of vertices
        bm->G = (int *)malloc(2 * bm->V * sizeof(int)); // Allocate memory for adjacency list
        bm->match = (int *)malloc(2 * bm->V * sizeof(int)); // Allocate memory for match array
        bm->used = (int *)malloc(bm->V * sizeof(int)); // Allocate memory for used array
        init(bm); // Initialize the BitMatching instance

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
                if (gcd(a[i], b[j])!= 1) { // If GCD is not 1, add an edge
                    add(bm, i, j);
                }
            }
        }

        // Execute the matching algorithm and print the result
        printf("%d\n", exec(bm)); // Print the result

        free(bm->G); // Free the memory allocated for adjacency list
        free(bm->match); // Free the memory allocated for match array
        free(bm->used); // Free the memory allocated for used array
        free(bm); // Free the memory allocated for BitMatching instance
    }
    return 0; // End of the program
}

