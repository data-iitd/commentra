#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAXN 520

typedef long long ll;

/**
 * Bit Matching Algorithm
 *
 * Time Complexity: O(EV)
 */
struct BitMatching {
    int G[2*MAXN][2]; // Graph representation using adjacency list
    int match[2*MAXN]; // Array to store the match of each node
    bool used[2*MAXN]; // Array to keep track of used nodes in DFS

    /// Initialize the graph
    void init() {
        for (int i = 0; i < 2*MAXN; i++) {
            for (int j = 0; j < 2; j++) {
                G[i][j] = -1; // Clear all edges
            }
        }
    }

    /// Add an edge between node a and node b in the bipartite graph
    void add(int a, int b) {
        G[a][0] = b+MAXN; // Add edge from a to b+MAXN
        G[b+MAXN][1] = a; // Add edge from b+MAXN to a
    }

    /// Depth-First Search to find augmenting paths
    bool dfs(int v) {
        used[v] = true; // Mark the node as visited
        for (int i = 0; i < 2; i++) {
            int u = G[v][i], w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) { // If the node is not matched or can find an augmenting path
                match[v] = u; // Assign the match
                match[u] = v; // Assign the match
                return true; // Return true as we found an augmenting path
            }
        }
        return false; // Return false if no augmenting path is found
    }

    /// Execute the bipartite matching algorithm
    int exec() {
        int res = 0; // Initialize the result
        memset(match, -1, sizeof(match)); // Initialize all matches to -1 (no match)
        for (int v = 0; v < MAXN; v++) {
            if (match[v] < 0) { // If the node is not matched
                memset(used, 0, sizeof(used)); // Reset the used array
                if (dfs(v)) { // Perform DFS from the node
                    res++; // Increment the result if an augmenting path is found
                }
            }
        }
        return res; // Return the total number of matches found
    }
};

int main() {
    while (true) {
        int n, m;
        scanf("%d %d", &n, &m); // Read the number of elements in the two sets
        if (!n) break; // If n is 0, break the loop
        BitMatching bm; // Create an instance of BitMatching
        bm.init(); // Initialize the bipartite graph
        int a[n], b[m]; // Arrays to store the elements of the two sets
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); // Read the elements of the first set
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]); // Read the elements of the second set
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j])!= 1) { // Check if the GCD is not 1
                    bm.add(i, j); // Add an edge between the corresponding nodes if GCD is not 1
                }
            }
        }
        printf("%d\n", bm.exec()); // Execute the bipartite matching and print the result
    }
    return 0;
}

