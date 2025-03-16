#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> g; // Adjacency list for the graph
vector<int> vis; // Visited array
int n, m, ci = 0, cb = 0, cc = 0; // Number of nodes, edges, and counters

// Depth-First Search (DFS) function to determine if a graph is bipartite
bool dfs(int x) {
    stack<pair<int, int>> stk; // Stack for DFS
    bool flag = true; // Flag to check bipartiteness
    stk.push({x, 1}); // Starting DFS from node x with color 1

    while (!stk.empty()) {
        auto [u, col] = stk.top(); stk.pop(); // Get current node and its color
        if (vis[u]) { // If the node has been visited, check if the color is consistent
            flag &= (vis[u] == col);
            continue;
        }
        vis[u] = col; // Mark the node as visited with the current color
        for (int i : g[u]) {
            stk.push({i, 3 - col}); // Add adjacent nodes to the stack with the opposite color
        }
    }
    return flag;
}

int main() {
    cin >> n >> m; // Reading the number of nodes and edges
    vis.resize(n + 1, 0); // Initializing visited list
    g.resize(n + 1); // Creating adjacency list

    // Constructing the graph by reading edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // Adding edge u-v
        g[v].push_back(u); // Adding edge v-u (undirected graph)
    }

    // Traversing the graph to classify nodes
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) { // If the node has not been visited
            if (g[i].empty()) {
                ci++; // Increment the count of isolated nodes
            } else {
                if (dfs(i)) {
                    cb++; // Increment the count of bipartite graphs
                } else {
                    cc++; // Increment the count of connected components that are not bipartite
                }
            }
        }
    }

    // Calculating and printing the result based on the counts of isolated, bipartite, and connected components
    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl;

    return 0;
}

// <END-OF-CODE>
