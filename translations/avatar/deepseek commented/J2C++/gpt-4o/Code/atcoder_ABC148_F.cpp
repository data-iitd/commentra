#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void dfs(int u, vector<int>& d, const vector<vector<int>>& edges) {
    for (int nu : edges[u]) {
        if (d[nu] == numeric_limits<int>::max()) {
            d[nu] = d[u] + 1;
            dfs(nu, d, edges);
        }
    }
}

int main() {
    int N, u, v;
    cin >> N >> u >> v;
    u--; // Convert to 0-based index
    v--; // Convert to 0-based index

    // Initialize the adjacency list for the graph
    vector<vector<int>> edges(N);
    
    // Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // Initialize the distance array for the first DFS traversal starting from node u
    vector<int> d(N, numeric_limits<int>::max());
    d[u] = 0;

    // Perform DFS from node u to populate the distance array d
    dfs(u, d, edges);

    // Initialize the distance array for the second DFS traversal starting from node v
    vector<int> e(N, numeric_limits<int>::max());
    e[v] = 0;

    // Perform DFS from node v to populate the distance array e
    dfs(v, e, edges);

    // Find the maximum value of e[i] where d[i] < e[i]
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Print the result based on the maximum value found
    if (q <= 0) {
        cout << 0 << endl;
    } else {
        cout << q - 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
