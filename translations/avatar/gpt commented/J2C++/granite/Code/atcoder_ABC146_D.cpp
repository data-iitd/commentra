
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Number of nodes in the graph
int n;
// Adjacency list representation of the graph, where each node points to a list of edges
vector<vector<pair<int, int>>> g;
// Array to store the answer for each edge
vector<int> ans;

// Depth-first search function to traverse the graph and assign colors to edges
void dfs(int to, int color, int parents) {
    int k = 1; // Start coloring with color 1
    for (auto e : g[to]) {
        // Skip the edge leading back to the parent node
        if (e.second == parents) continue;
        // If the current color is the same as the edge color, increment it
        if (k == color) k++;
        // Assign the color to the edge
        ans[e.first] = k;
        // Recursively call dfs for the connected node
        dfs(e.second, k, to);
        k++; // Increment color for the next edge
    }
}

int main() {
    // Create a Scanner object for input
    // Read the number of nodes
    cin >> n;
    // Initialize the adjacency list for the graph
    g.resize(n);
    for (int i = 0; i < n; i++) {
        g[i].reserve(n - 1);
    }
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        // Read the two endpoints of the edge, adjusting for 0-based indexing
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        // Add the edge to both endpoints' adjacency lists
        g[a].emplace_back(i, b);
        g[b].emplace_back(i, a);
    }
    // Initialize the answer array to store results for each edge
    ans.resize(n - 1);
    // Perform a depth-first search starting from node 0
    dfs(0, -1, -1);
    // Find the maximum value in the ans array
    int max = *max_element(ans.begin(), ans.end());
    // Output the maximum value found
    cout << max << endl;
    // Output the results for each edge
    for (int c : ans) {
        cout << c << endl;
    }
    return 0;
}

// End of code