
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

/**
 * @brief BitMatching template structure for solving Bipartite Graph Matching problem.
 *
 * @tparam V The maximum number of vertices in the graph.
 */
template<int V>
struct BitMatching {
    std::vector<int> G[2*V]; ///< Adjacency list for the graph.
    int match[2*V]; ///< Stores the matching result for each vertex.
    bool used[2*V]; ///< Stores whether a vertex is being processed or not.

    /**
     * @brief Initializes the graph data structures.
     */
    void init() {
        for (int i = 0; i < 2*V; i++) {
            G[i].clear(); ///< Clears the adjacency list for the current vertex.
        }
    }

    /**
     * @brief Adds an edge between two vertices in the graph.
     *
     * @param a The source vertex.
     * @param b The destination vertex.
     */
    void add(int a, int b) {
        G[a].push_back(b+V); ///< Adds the destination vertex to the adjacency list of the source vertex.
        G[b+V].push_back(a); ///< Adds the source vertex to the adjacency list of the destination vertex.
    }

    /**
     * @brief Performs Depth First Search (DFS) algorithm to find a matching between vertices.
     *
     * @param v The current vertex being processed.
     *
     * @return true if a matching is found, false otherwise.
     */
    bool dfs(int v) {
        used[v] = true; ///< Marks the current vertex as being processed.

        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i], w = match[u]; ///< Gets the neighboring vertex and its matching vertex.

            if (w < 0 || (!used[w] && dfs(w))) { ///< If the neighboring vertex is not matched or can be matched, update the matching result.
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false; ///< If no matching is found, return false.
    }

    /**
     * @brief Executes the Bipartite Graph Matching algorithm.
     *
     * @return The number of matched vertices.
     */
    int exec() {
        int res = 0; ///< Initializes the result variable.
        memset(match, -1, sizeof(match)); ///< Initializes the matching array with -1.

        for (int v = 0; v < V; v++) { ///< Iterates through all vertices in the graph.
            if (match[v] < 0) { ///< If the current vertex is not matched, perform DFS to find a matching.
                memset(used, 0, sizeof(used));
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res; ///< Returns the number of matched vertices.
    }
};

/**
 * @brief Constants for the maximum number of vertices in the graph.
 */
const int MN = 520;

/**
 * @brief Instantiates the BitMatching template structure with the given constant.
 */
BitMatching<MN> bm;

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
        cin >> n >> m;

        if (!n) break; ///< If the number of vertices is 0, breaks the loop.

        bm.init(); ///< Initializes the graph data structures.

        int a[n], b[m]; ///< Reads the input data for vertices a and b.

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) { ///< Iterates through all vertices a.
            for (int j = 0; j < m; j++) { ///< Iterates through all vertices b.
                if (gcd(a[i], b[j]) != 1) { ///< If the GCD of a[i] and b[j] is not 1, adds an edge between them.
                    bm.add(i, j);
                }
            }
        }

        cout << bm.exec() << endl; ///< Executes the Bipartite Graph Matching algorithm and prints the result.
    }

    return 0;
}

