

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

/**
 * @brief BitMatching template structure for solving Bipartite Graph Matching problem.
 *
 * @tparam V The maximum number of vertices in the graph.
 */
typedef struct {
    int G[2*V][2*V]; ///< Adjacency matrix for the graph.
    int match[2*V]; ///< Stores the matching result for each vertex.
    bool used[2*V]; ///< Stores whether a vertex is being processed or not.
} BitMatching;

/**
 * @brief Initializes the graph data structures.
 *
 * @param bm The BitMatching structure to be initialized.
 */
void init(BitMatching *bm) {
    int V = 2*bm->V;
    for (int i = 0; i < V; i++) {
        memset(bm->G[i], 0, sizeof(bm->G[i])); ///< Clears the adjacency matrix for the current vertex.
    }
}

/**
 * @brief Adds an edge between two vertices in the graph.
 *
 * @param bm The BitMatching structure to be modified.
 * @param a The source vertex.
 * @param b The destination vertex.
 */
void add(BitMatching *bm, int a, int b) {
    bm->G[a][b+bm->V] = 1; ///< Adds the destination vertex to the adjacency matrix of the source vertex.
    bm->G[b+bm->V][a] = 1; ///< Adds the source vertex to the adjacency matrix of the destination vertex.
}

/**
 * @brief Performs Depth First Search (DFS) algorithm to find a matching between vertices.
 *
 * @param bm The BitMatching structure to be used.
 * @param v The current vertex being processed.
 *
 * @return true if a matching is found, false otherwise.
 */
bool dfs(BitMatching *bm, int v) {
    bm->used[v] = true; ///< Marks the current vertex as being processed.

    for (int i = 0; i < 2*bm->V; i++) {
        int u = i, w = bm->match[u]; ///< Gets the neighboring vertex and its matching vertex.

        if (w < 0 || (!bm->used[w] && dfs(bm, w))) { ///< If the neighboring vertex is not matched or can be matched, update the matching result.
            bm->match[v] = u;
            bm->match[u] = v;
            return true;
        }
    }
    return false; ///< If no matching is found, return false.
}

/**
 * @brief Executes the Bipartite Graph Matching algorithm.
 *
 * @param bm The BitMatching structure to be used.
 *
 * @return The number of matched vertices.
 */
int exec(BitMatching *bm) {
    int res = 0; ///< Initializes the result variable.
    memset(bm->match, -1, sizeof(bm->match)); ///< Initializes the matching array with -1.

    for (int v = 0; v < bm->V; v++) { ///< Iterates through all vertices in the graph.
        if (bm->match[v] < 0) { ///< If the current vertex is not matched, perform DFS to find a matching.
            memset(bm->used, 0, sizeof(bm->used));
            if (dfs(bm, v)) {
                res++;
            }
        }
    }
    return res; ///< Returns the number of matched vertices.
}

/**
 * @brief Constants for the maximum number of vertices in the graph.
 */
#define MN 520

/**
 * @brief Instantiates the BitMatching template structure with the given constant.
 */
BitMatching bm;

/**
 * @brief Computes the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
 *
 * @param a The first number.
 * @param b The second number.
 *
 * @return The greatest common divisor of the two numbers.
 */
ll gcd(ll a, ll b) {
    if (b == 0) return a; ///< Base case: if b is 0, return a.
    return gcd(b, a%b); ///< Recursive case: call gcd with b and the remainder of a divided by b.
}

/**
 * @brief Reads input data and performs the Bipartite Graph Matching algorithm.
 */
int main() {
    while (true) { ///< Loops through multiple test cases.
        int n, m; ///< Reads the number of vertices and edges in the graph.
        scanf("%d%d", &n, &m);

        if (!n) break; ///< If the number of vertices is 0, breaks the loop.

        init(&bm); ///< Initializes the graph data structures.

        int a[n], b[m]; ///< Reads the input data for vertices a and b.

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) { ///< Iterates through all vertices a.
            for (int j = 0; j < m; j++) { ///< Iterates through all vertices b.
                if (gcd(a[i], b[j])!= 1) { ///< If the GCD of a[i] and b[j] is not 1, adds an edge between them.
                    add(&bm, i, j);
                }
            }
        }

        printf("%d\n", exec(&bm)); ///< Executes the Bipartite Graph Matching algorithm and prints the result.
    }

    return 0;
}

