#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MN 520

typedef long long ll;

typedef struct {
    int G[2 * MN][2 * MN]; // Adjacency list for the graph.
    int match[2 * MN]; // Stores the matching result for each vertex.
    int used[2 * MN]; // Stores whether a vertex is being processed or not.
    int size[2 * MN]; // Size of each adjacency list.
} BitMatching;

/**
 * @brief Initializes the graph data structures.
 */
void init(BitMatching *bm) {
    for (int i = 0; i < 2 * MN; i++) {
        bm->size[i] = 0; // Clears the adjacency list for the current vertex.
    }
}

/**
 * @brief Adds an edge between two vertices in the graph.
 *
 * @param bm Pointer to the BitMatching structure.
 * @param a The source vertex.
 * @param b The destination vertex.
 */
void add(BitMatching *bm, int a, int b) {
    bm->G[a][bm->size[a]++] = b + MN; // Adds the destination vertex to the adjacency list of the source vertex.
    bm->G[b + MN][bm->size[b + MN]++] = a; // Adds the source vertex to the adjacency list of the destination vertex.
}

/**
 * @brief Performs Depth First Search (DFS) algorithm to find a matching between vertices.
 *
 * @param bm Pointer to the BitMatching structure.
 * @param v The current vertex being processed.
 *
 * @return 1 if a matching is found, 0 otherwise.
 */
int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1; // Marks the current vertex as being processed.

    for (int i = 0; i < bm->size[v]; i++) {
        int u = bm->G[v][i], w = bm->match[u]; // Gets the neighboring vertex and its matching vertex.

        if (w < 0 || (!bm->used[w] && dfs(bm, w))) { // If the neighboring vertex is not matched or can be matched, update the matching result.
            bm->match[v] = u;
            bm->match[u] = v;
            return 1;
        }
    }
    return 0; // If no matching is found, return 0.
}

/**
 * @brief Executes the Bipartite Graph Matching algorithm.
 *
 * @param bm Pointer to the BitMatching structure.
 * @return The number of matched vertices.
 */
int exec(BitMatching *bm) {
    int res = 0; // Initializes the result variable.
    memset(bm->match, -1, sizeof(bm->match)); // Initializes the matching array with -1.

    for (int v = 0; v < MN; v++) { // Iterates through all vertices in the graph.
        if (bm->match[v] < 0) { // If the current vertex is not matched, perform DFS to find a matching.
            memset(bm->used, 0, sizeof(bm->used));
            if (dfs(bm, v)) {
                res++;
            }
        }
    }
    return res; // Returns the number of matched vertices.
}

/**
 * @brief Computes the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
 *
 * @param a The first number.
 * @param b The second number.
 *
 * @return The greatest common divisor of the two numbers.
 */
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a.
    return gcd(b, a % b); // Recursive case: call gcd with b and the remainder of a divided by b.
}

/**
 * @brief Reads input data and performs the Bipartite Graph Matching algorithm.
 */
int main() {
    BitMatching bm; // Instantiates the BitMatching structure.
    while (1) { // Loops through multiple test cases.
        int n, m; // Reads the number of vertices and edges in the graph.
        scanf("%d %d", &n, &m);

        if (n == 0) break; // If the number of vertices is 0, breaks the loop.

        init(&bm); // Initializes the graph data structures.

        int a[MN], b[MN]; // Reads the input data for vertices a and b.

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) { // Iterates through all vertices a.
            for (int j = 0; j < m; j++) { // Iterates through all vertices b.
                if (gcd(a[i], b[j]) != 1) { // If the GCD of a[i] and b[j] is not 1, adds an edge between them.
                    add(&bm, i, j);
                }
            }
        }

        printf("%d\n", exec(&bm)); // Executes the Bipartite Graph Matching algorithm and prints the result.
    }

    return 0;
}

// <END-OF-CODE>
