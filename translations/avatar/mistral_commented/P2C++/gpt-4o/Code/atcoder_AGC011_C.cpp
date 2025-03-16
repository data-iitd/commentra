#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS traversal from a given vertex 'x'
bool dfs(int x, vector<int>& vis, vector<vector<int>>& g) {
    stack<pair<int, int>> stk; // Stack to hold pairs of (vertex, color)
    bool flag = true;

    // Pushing the current vertex 'x' into the stack with color '1'
    stk.push({x, 1});

    // Traversing the graph until the stack is empty
    while (!stk.empty()) {
        auto [u, col] = stk.top();
        stk.pop();

        // If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }

        // Mark the current vertex 'u' as visited with the current color 'col'
        vis[u] = col;

        // Recursively traverse all the adjacent vertices of 'u'
        for (int i : g[u]) {
            stk.push({i, 3 - col});
        }
    }

    // Return the flag indicating whether all vertices in the connected component have the same color or not
    return flag;
}

int main() {
    // Taking the number of vertices (n) and edges (m) as input
    int n, m;
    cin >> n >> m;

    // Initializing the visited list and other variables
    vector<int> vis(n + 1, 0);
    int ci = 0, cb = 0, cc = 0;
    vector<vector<int>> g(n + 1);

    // Adding edges to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Adding an edge between vertices 'u' and 'v' in both the adjacency lists
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Finding the number of isolated vertices and connected components
    for (int i = 1; i <= n; i++) {
        // If the current vertex 'i' is not visited yet
        if (vis[i] == 0) {
            // If the current vertex 'i' has no edges, then it is an isolated vertex
            if (g[i].empty()) {
                ci++;
            }
            // Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
            else {
                if (dfs(i, vis, g)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }

    // Calculating and printing the final answer
    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl;

    return 0;
}

// <END-OF-CODE>
