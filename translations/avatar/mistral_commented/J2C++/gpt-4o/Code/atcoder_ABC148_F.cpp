#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Depth-first search recursive helper function
void dfs(int u, vector<int>& d, const vector<vector<int>>& edges) {
    for (int nu : edges[u]) {
        if (d[nu] == numeric_limits<int>::max()) {
            // Mark the current node as visited and update the distance of its neighbors
            d[nu] = d[u] + 1;
            dfs(nu, d, edges);
        }
    }
}

int main() {
    // Read the number of nodes N from the standard input
    int N;
    cin >> N;

    // Read the indices u and v of the two nodes from the standard input
    int u, v;
    cin >> u >> v;
    u--; // Convert to 0-based index
    v--; // Convert to 0-based index

    // Initialize the adjacency lists for the graph
    vector<vector<int>> edges(N);
    
    // Read the edges of the graph from the standard input and add them to the adjacency lists
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // Initialize the distance arrays d and e for depth-first search
    vector<int> d(N, numeric_limits<int>::max());
    vector<int> e(N, numeric_limits<int>::max());

    // Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
    d[u] = 0; // Starting point for u
    dfs(u, d, edges);
    
    e[v] = 0; // Starting point for v
    dfs(v, e, edges);

    // Find the maximum difference between the distances of any node from u and v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Print the result: the maximum difference between the distances of any node from u and v
    if (q <= 0) {
        cout << 0 << endl;
    } else {
        cout << q - 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
