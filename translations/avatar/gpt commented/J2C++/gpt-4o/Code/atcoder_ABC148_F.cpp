#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void dfs(int u, vector<int>& d, const vector<vector<int>>& edges) {
    for (int nu : edges[u]) {
        if (d[nu] == numeric_limits<int>::max()) { // If the node has not been visited
            d[nu] = d[u] + 1; // Update the distance
            dfs(nu, d, edges); // Recursively visit the next node
        }
    }
}

int main() {
    // Initialize the input
    int N, u, v;
    cin >> N >> u >> v;
    u--; // Convert to zero-based index
    v--; // Convert to zero-based index

    // Create an adjacency list to represent the edges of the graph
    vector<vector<int>> edges(N);
    
    // Read the edges and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        edges[a].push_back(b); // Add edge from a to b
        edges[b].push_back(a); // Add edge from b to a (undirected graph)
    }

    // Initialize distance array for the first node (u)
    vector<int> d(N, numeric_limits<int>::max());
    d[u] = 0; // Distance to itself is 0

    // Perform DFS from node u to calculate distances
    dfs(u, d, edges);

    // Initialize distance array for the second node (v)
    vector<int> e(N, numeric_limits<int>::max());
    e[v] = 0; // Distance to itself is 0

    // Perform DFS from node v to calculate distances
    dfs(v, e, edges);

    // Find the maximum distance from node u to any node that is closer to v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) { // Check if node i is closer to u than to v
            if (e[i] > q) { // Update q if the distance to v is greater
                q = e[i];
            }
        }
    }

    // Output the result based on the maximum distance found
    if (q <= 0) {
        cout << 0 << endl; // If no valid distance found, print 0
    } else {
        cout << q - 1 << endl; // Print the maximum distance minus 1
    }

    return 0;
}

// <END-OF-CODE>
