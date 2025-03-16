
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 520 ///< Defines the maximum number of vertices in the graph.

/**
 * @brief BitMatching structure for solving Bipartite Graph Matching problem.
 */
typedef struct {
    int G[2*V][2*V]; ///< Adjacency list for the graph.
    int match[2*V]; ///< Stores the matching result for each vertex.
    int used[2*V]; ///< Stores whether a vertex is being processed or not.
} BitMatching;

/**
 * @brief Initializes the graph data structures.
 *
 * @param bm The BitMatching structure.
 */
void init(BitMatching *bm) {
    for (int i = 0; i < 2*V; i++) {
        bm->G[i][0] = 0; ///< Clears the adjacency list for the current vertex.
    }
}

/**
 * @brief Adds an edge between two vertices in the graph.
 *
 * @param bm The BitMatching structure.
 * @param a The source vertex.
 * @param b The destination vertex.
 */
void add(BitMatching *bm, int a, int b) {
    bm->G[a][bm->G[a][0]+1] = b+V; ///< Adds the destination vertex to the adjacency list of the source vertex.
    bm->G[b+V][bm->G[b+V][0]+1] = a; ///< Adds the source vertex to the adjacency list of the destination vertex.
    bm->G[a][0]++; ///< Increments the number of vertices in the adjacency list of the source vertex.
    bm->G[b+V][0]++; ///< Increments the number of vertices in the adjacency list of the destination vertex.
}

/**
 * @brief Performs Depth First Search (DFS) algorithm to find a matching between vertices.
 *
 * @param bm The BitMatching structure.
 * @param v The current vertex being processed.
 *
 * @return true if a matching is found, false otherwise.
 */
int dfs(BitMatching *bm, int v) {
    bm->used[v] = 1; ///< Marks the current vertex as being processed.

    for (int i = 1; i <= bm->G[v][0]; i++) {
        int u = bm->G[v][i], w = bm->match[u]; ///< Gets the neighboring vertex and its matching vertex.

        if (w < 0 || (!bm->used[w] && dfs(bm, w))) { ///< If the neighboring vertex is not matched or can be matched, update the matching result.
            bm->match[v] = u;
            bm->match[u] = v;
            return 1;
        }
    }
    return 0; ///< If no matching is found, return false.
}

/**
 * @brief Executes the Bipartite Graph Matching algorithm.
 *
 * @param bm The BitMatching structure.
 *
 * @return The number of matched vertices.
 */
int exec(BitMatching *bm) {
    int res = 0; ///< Initializes the result variable.
    memset(bm->match, -1, sizeof(bm->match)); ///< Initializes the matching array with -1.

    for (int v = 0; v < V; v++) { ///< Iterates through all vertices in the graph.
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
 * @brief Computes the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
 *
 * @param a The first number.
 * @param b The second number.
 *
 * 