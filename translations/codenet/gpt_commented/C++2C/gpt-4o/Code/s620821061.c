#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MN 520 // Maximum number of vertices

typedef long long ll;

<<<<<<< HEAD
typedef struct {
=======
// Structure for the BitMatching algorithm
struct BitMatching {
>>>>>>> 98c87cb78a (data updated)
    int G[2 * MN][2 * MN]; // Adjacency list for the bipartite graph
    int match[2 * MN];     // Array to store matches for vertices
    int used[2 * MN];      // Array to track visited vertices during DFS
    int size[2 * MN];      // Size of each adjacency list
<<<<<<< HEAD
} BitMatching;

void init(BitMatching *bm) {
    for (int i = 0; i < 2 * MN; i++) {
        bm->size[i] = 0; // Initialize size of each adjacency list
    }
}

void add(BitMatching *bm, int a, int b) {
=======
};

// Initializes the graph by clearing the adjacency list
void init(struct BitMatching *bm) {
    for (int i = 0; i < 2 * MN; i++) {
        bm->size[i] = 0; // Reset size of each adjacency list
    }
}

// Adds an edge between vertex a and vertex b in the bipartite graph
void add(struct BitMatching *bm, int a, int b) {
>>>>>>> 98c87cb78a (data updated)
    bm->G[a][bm->size[a]++] = b + MN; // Connect a to b in the second set
    bm->G[b + MN][bm->size[b + MN]++] = a; // Connect b to a in the first set
}

<<<<<<< HEAD
int dfs(BitMatching *bm, int v) {
=======
// Depth-First Search to find an augmenting path
int dfs(struct BitMatching *bm, int v) {
>>>>>>> 98c87cb78a (data updated)
    bm->used[v] = 1; // Mark the current vertex as visited
    for (int i = 0; i < bm->size[v]; i++) {
        int u = bm->G[v][i], w = bm->match[u]; // Get the matched vertex for u
        // If u is unmatched or we can find an augmenting path
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) {
            bm->match[v] = u; // Match v with u
            bm->match[u] = v; // Match u with v
<<<<<<< HEAD
            return 1;         // Found a match
=======
            return 1; // Found a match
>>>>>>> 98c87cb78a (data updated)
        }
    }
    return 0; // No match found
}

<<<<<<< HEAD
int exec(BitMatching *bm) {
=======
// Executes the matching algorithm and returns the size of the maximum matching
int exec(struct BitMatching *bm) {
>>>>>>> 98c87cb78a (data updated)
    int res = 0; // Result variable to count matches
    memset(bm->match, -1, sizeof(bm->match)); // Initialize matches to -1 (unmatched)
    for (int v = 0; v < MN; v++) {
        if (bm->match[v] < 0) { // If vertex v is unmatched
            memset(bm->used, 0, sizeof(bm->used)); // Reset visited array
            if (dfs(bm, v)) { // Try to find a match for v
                res++; // Increment the result if a match is found
            }
        }
    }
    return res; // Return the total number of matches
}

<<<<<<< HEAD
/// Function to compute the greatest common divisor (GCD) of two numbers
=======
// Function to compute the greatest common divisor (GCD) of two numbers
>>>>>>> 98c87cb78a (data updated)
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive case: GCD of b and a mod b
}

int main() {
<<<<<<< HEAD
    BitMatching bm; // Create an instance of BitMatching
=======
    struct BitMatching bm; // Create an instance of BitMatching
>>>>>>> 98c87cb78a (data updated)
    while (1) {
        int n, m; // Number of elements in two sets
        scanf("%d %d", &n, &m); // Read the sizes of the two sets
        if (n == 0) break; // Exit if n is 0 (no more input)

        init(&bm); // Initialize the BitMatching instance
<<<<<<< HEAD
        int a[n], b[m]; // Arrays to hold the elements of the two sets
=======
        int a[MN], b[MN]; // Arrays to hold the elements of the two sets
>>>>>>> 98c87cb78a (data updated)
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

// <END-OF-CODE>
