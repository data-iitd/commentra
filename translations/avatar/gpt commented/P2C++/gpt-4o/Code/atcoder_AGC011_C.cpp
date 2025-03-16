#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and check for bipartiteness
bool dfs(int x, vector<int>& vis, const vector<vector<int>>& g) {
    stack<pair<int, int>> stk;  // Stack for DFS
    bool flag = true;  // Flag for bipartiteness
    stk.push({x, 1});  // Start DFS from node x with color 1

    while (!stk.empty()) {
        auto [u, col] = stk.top();  // Get the current node and its color
        stk.pop();
        if (vis[u]) {  // If the node has already been visited
            flag &= (vis[u] == col);  // Check if the color matches
            continue;
        }
        vis[u] = col;  // Mark the node as visited with the current color
        for (int i : g[u]) {  // Iterate through all adjacent nodes
            stk.push({i, 3 - col});  // Push the adjacent node with the alternate color
        }
    }
    return flag;  // Return whether the component is bipartite
}

int main() {
    // Read the number of nodes (n) and edges (m) from input
    int n, m;
    cin >> n >> m;

    // Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
    vector<int> vis(n + 1, 0);
    int ci = 0, cb = 0, cc = 0;

    // Create an adjacency list to represent the graph
    vector<vector<int>> g(n + 1);

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);  // Add edge from u to v
        g[v].push_back(u);  // Add edge from v to u (undirected graph)
    }

    // Iterate through all nodes to count isolated and bipartite components
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {  // If the node has not been visited
            if (g[i].empty()) {  // Check if the node is isolated
                ci++;  // Increment isolated component counter
            } else {
                if (dfs(i, vis, g)) {  // Perform DFS and check if the component is bipartite
                    cb++;  // Increment bipartite component counter
                } else {
                    cc++;  // Increment non-bipartite component counter
                }
            }
        }
    }

    // Calculate and print the final result based on the counts of components
    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl;

    return 0;
}

// <END-OF-CODE>
