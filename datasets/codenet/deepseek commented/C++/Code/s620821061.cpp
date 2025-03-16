#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

/**
 * Bit Matching Algorithm
 *
 * Time Complexity: O(EV)
 */
template<int V>
struct BitMatching {
    vector<int> G[2*V]; // Graph representation using adjacency list
    int match[2*V]; // Array to store the match of each node
    bool used[2*V]; // Array to keep track of used nodes in DFS

    /// Initialize the graph
    void init() {
        for (int i = 0; i < 2*V; i++) {
            G[i].clear(); // Clear all edges
        }
    }

    /// Add an edge between node a and node b in the bipartite graph
    void add(int a, int b) {
        G[a].push_back(b+V); // Add edge from a to b+V
        G[b+V].push_back(a); // Add edge from b+V to a
    }

    /// Depth-First Search to find augmenting paths
    bool dfs(int v) {
        used[v] = true; // Mark the node as visited
        for (int i = 0; i < G[v].size(); i++) {
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
        for (int v = 0; v < V; v++) {
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

const int MN = 520;
BitMatching<MN> bm; // Create an instance of BitMatching with maximum number of vertices as 520

/// Function to compute the greatest common divisor (GCD) of two numbers
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a%b); // Recursive call: compute GCD of b and the remainder of a divided by b
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m; // Read the number of elements in the two sets
        if (!n) break; // If n is 0, break the loop
        bm.init(); // Initialize the bipartite graph
        int a[n], b[m]; // Arrays to store the elements of the two sets
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Read the elements of the first set
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i]; // Read the elements of the second set
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j]) != 1) { // Check if the GCD is not 1
                    bm.add(i, j); // Add an edge between the corresponding nodes if GCD is not 1
                }
            }
        }
        cout << bm.exec() << endl; // Execute the bipartite matching and print the result
    }
    return 0;
}
