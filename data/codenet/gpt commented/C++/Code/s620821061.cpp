#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

/**
 * BitMatching class for finding maximum matching in a bipartite graph.
 * The algorithm runs in O(EV) time complexity.
 */
template<int V>
struct BitMatching {
    vector<int> G[2*V]; // Adjacency list for the bipartite graph
    int match[2*V];     // Array to store matches for vertices
    bool used[2*V];     // Array to track visited vertices during DFS

    /// Initializes the graph by clearing the adjacency list
    void init() {
        for (int i = 0; i < 2*V; i++) {
            G[i].clear();
        }
    }

    /// Adds an edge between vertex a and vertex b in the bipartite graph
    /// Note: b is adjusted by adding V to differentiate between the two sets
    void add(int a, int b) {
        G[a].push_back(b + V); // Connect a to b in the second set
        G[b + V].push_back(a); // Connect b to a in the first set
    }

    /// Depth-First Search to find an augmenting path
    bool dfs(int v) {
        used[v] = true; // Mark the current vertex as visited
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i], w = match[u]; // Get the matched vertex for u
            // If u is unmatched or we can find an augmenting path
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u; // Match v with u
                match[u] = v; // Match u with v
                return true;  // Found a match
            }
        }
        return false; // No match found
    }

    /// Executes the matching algorithm and returns the size of the maximum matching
    int exec() {
        int res = 0; // Result variable to count matches
        memset(match, -1, sizeof(match)); // Initialize matches to -1 (unmatched)
        for (int v = 0; v < V; v++) {
            if (match[v] < 0) { // If vertex v is unmatched
                memset(used, 0, sizeof(used)); // Reset visited array
                if (dfs(v)) { // Try to find a match for v
                    res++; // Increment the result if a match is found
                }
            }
        }
        return res; // Return the total number of matches
    }
};

const int MN = 520; // Maximum number of vertices
BitMatching<MN> bm; // Create an instance of BitMatching

/// Function to compute the greatest common divisor (GCD) of two numbers
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive case: GCD of b and a mod b
}

int main() {
    while (true) {
        int n, m; // Number of elements in two sets
        cin >> n >> m; // Read the sizes of the two sets
        if (!n) break; // Exit if n is 0 (no more input)

        bm.init(); // Initialize the BitMatching instance
        int a[n], b[m]; // Arrays to hold the elements of the two sets
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Read elements of the first set
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i]; // Read elements of the second set
        }

        // Build the bipartite graph based on the GCD condition
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j]) != 1) { // If GCD is not 1, add an edge
                    bm.add(i, j);
                }
            }
        }
        
        // Execute the matching algorithm and print the result
        cout << bm.exec() << endl;
    }
    return 0; // End of the program
}
