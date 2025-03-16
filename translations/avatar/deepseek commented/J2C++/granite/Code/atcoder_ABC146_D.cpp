
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<pair<int, int>>> g; // Step 1: Declare the graph as an adjacency list
vector<int> ans; // Step 3: Declare the answer array to store edge colors

void dfs(int to, int color, int parent) { // Step 4: Define the DFS function
    int k = 1; // Initialize the color counter
    for (pair<int, int> e : g[to]) { // Iterate through the adjacency list of the current node
        if (e.first == parent) continue; // Skip if the neighbor is the parent
        if (k == color) k++; // Ensure the color is not the same as the parent's color
        ans[e.second] = k; // Assign the color to the edge
        dfs(e.first, k, to); // Recursively call DFS for the neighbor
        k++; // Increment the color counter for the next edge
    }
}

int main() {
    cin >> n; // Read the number of nodes
    g.resize(n); // Initialize the graph
    for (int i = 0; i < n - 1; i++) { // Step 2: Read and populate the graph
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back({b, i}); // Add edge from a to b
        g[b].push_back({a, i}); // Add edge from b to a
    }
    ans.resize(n - 1); // Step 3: Initialize the answer array
    dfs(0, -1, -1); // Step 3: Call DFS with root node 0, initial color -1, and parent -1
    int max = *max_element(ans.begin(), ans.end()); // Step 5: Find the maximum color used
    cout << max << endl; // Step 5: Print the maximum color used
    for (int c : ans) {
        cout << c << endl; // Step 5: Print the colors assigned to each edge
    }
    return 0;
}

