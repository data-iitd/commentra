#include <iostream>
#include <vector>
using namespace std;

class Edge { // Define the Edge class
public:
    int id;
    int to;

    Edge(int id, int to) : id(id), to(to) {}
};

vector<vector<Edge>> g; // Step 1: Declare the graph as an adjacency list
vector<int> ans; // Step 3: Declare the answer array to store edge colors

void dfs(int to, int color, int parent) { // Step 4: Define the DFS function
    int k = 1; // Initialize the color counter
    for (const Edge& e : g[to]) { // Iterate through the adjacency list of the current node
        if (e.to == parent) continue; // Skip if the neighbor is the parent
        if (k == color) k++; // Ensure the color is not the same as the parent's color
        ans[e.id] = k; // Assign the color to the edge
        dfs(e.to, k, to); // Recursively call DFS for the neighbor
        k++; // Increment the color counter for the next edge
    }
}

int main() {
    int n;
    cin >> n; // Read the number of nodes
    g.resize(n); // Initialize the graph
    for (int i = 0; i < n - 1; i++) { // Step 2: Read and populate the graph
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        g[a].emplace_back(i, b); // Add edge from a to b
        g[b].emplace_back(i, a); // Add edge from b to a
    }
    ans.resize(n - 1); // Step 3: Initialize the answer array
    dfs(0, -1, -1); // Step 3: Call DFS with root node 0, initial color -1, and parent -1
    int max_color = 0; // Step 5: Initialize max to find the maximum color used
    for (int temp : ans) {
        max_color = max(max_color, temp); // Step 5: Find the maximum color used
    }
    cout << max_color << endl; // Step 5: Print the maximum color used
    for (int c : ans) {
        cout << c << endl; // Step 5: Print the colors assigned to each edge
    }
    return 0;
}

// <END-OF-CODE>
