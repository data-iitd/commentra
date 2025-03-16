
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Constants for the maximum number of vertices in the graph.
 */
#define MN 520

/**
 * @brief Structure for the graph data structures.
 */
struct Graph {
    int G[2*MN]; ///< Adjacency list for the graph.
    int match[2*MN]; ///< Stores the matching result for each vertex.
    int used[2*MN]; ///< Stores whether a vertex is being processed or not.
};

/**
 * @brief Initializes the graph data structures.
 *
 * @param g The graph data structure.
 */
void init(Graph *g) {
    for (int i = 0; i < 2*MN; i++) {
        g->G[i] = 0; ///< Clears the adjacency list for the current vertex.
    }
}

/**
 * @brief Adds an edge between two vertices in the graph.
 *
 * @param g The graph data structure.
 * @param a The source vertex.
 * @param b The destination vertex.
 */
void add(Graph *g, int a, int b) {
    g->G[a] = b+MN; ///< Adds the destination vertex to the adjacency list of the source vertex.
    g->G[b+MN] = a; ///< Adds the source vertex to the adjacency list of the destination vertex.
}

/**
 * @brief Performs Depth First Search (DFS) algorithm to find a matching between vertices.
 *
 * @param g The graph data structure.
 * @param v The current vertex being processed.
 *
 * @return true if a matching is found, false otherwise.
 */
bool dfs(Graph *g, int v) {
    g->used[v] = 1; ///< Marks the current vertex as being processed.

    for (int i = g->G[v]; i; i = g->G[i]) {
        int u = i-MN, w = g->match[u]; ///< Gets the neighboring vertex and its matching vertex.

        if (w < 0 || (!g->used[w] && dfs(g, w))) { ///< If the neighboring vertex is not matched or can be matched, update the matching result.
            g->match[v] = u;
            g->match[u] = v;
            return true;
        }
    }
    return false; ///< If no matching is found, return false.
}

/**
 * @brief Executes the Bipartite Graph Matching algorithm.
 *
 * @param g The graph data structure.
 *
 * @return The number of matched vertices.
 */
int exec(Graph *g) {
    int res = 0; ///< Initializes the result variable.
    memset(g->match, -1, sizeof(g->match)); ///< Initializes the matching array with -1.

    for (int v = 0; v < MN; v++) { ///< Iterates through all vertices in the graph.
        if (g->match[v] < 0) { ///< If the current vertex is not matched, perform DFS to find a matching.
            memset(g->used, 0, sizeof(g->used));
            if (dfs(g, v)) {
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
 * @brief Instantiates the graph data structure.
 */
Graph g;

/**
 * @brief Computes the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
 *
 * @param a The first number.
 * @param b The second number.
 *
 * @return The greatest common divisor of the two numbers.
 */
int gcd(int a, int b) {
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

        init(&g); ///< Initializes the graph data structures.

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
                    add(&g, i, j);
                }
            }
        }

        printf("%d\n", exec(&g)); ///< Executes the Bipartite Graph Matching algorithm and prints the result.
    }

    return 0;
}

