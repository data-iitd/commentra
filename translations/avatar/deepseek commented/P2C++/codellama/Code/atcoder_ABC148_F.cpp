#include <bits/stdc++.h>
using namespace std;

// Function to read an integer from standard input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from standard input
vector<int> inpl() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

// Adjust indices to be zero-based
void adjust(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i]--;
    }
}

// Initialize the graph as a list of lists, each representing adjacency list of a node
vector<vector<int>> g;

// Read edges to construct the graph
void read_edges(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int a = v[i], b = v[i + 1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

// Initialize distance arrays to -1, will be populated during DFS
vector<int> ta_dist, ao_dist;

// Depth-First Search (DFS) function to compute distances from Ta
void ta_dfs(int node) {
    for (int v : g[node]) {
        if (ta_dist[v] != -1)  // If already visited, skip
            continue;
        ta_dist[v] = ta_dist[node] + 1;  // Update distance
        ta_dfs(v);  // Recursively visit neighbors
    }
}

// Depth-First Search (DFS) function to compute distances from Ao
void ao_dfs(int node) {
    for (int v : g[node]) {
        if (ao_dist[v] != -1)  // If already visited, skip
            continue;
        ao_dist[v] = ao_dist[node] + 1;  // Update distance
        ao_dfs(v);  // Recursively visit neighbors
    }
}

// Start DFS from Ao to compute distances
void ao_dfs_start(int node) {
    ao_dist[node] = 0;
    ao_dfs(node);
}

// Start DFS from Ta to compute distances
void ta_dfs_start(int node) {
    ta_dist[node] = 0;
    ta_dfs(node);
}

// Initialize result variable
int res = 0;

// Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
void find_max_dist() {
    for (int i = 0; i < g.size(); i++) {
        if (ta_dist[i] > ao_dist[i])  // Skip if Ta's distance is greater
            continue;
        res = max(res, ao_dist[i]);  // Update result with the maximum distance
    }
}

int main() {
    // Read the number of nodes, starting node for Ta, and starting node for Ao
    vector<int> v = inpl();
    int n = v[0], ta = v[1], ao = v[2];

    // Adjust indices to be zero-based
    adjust(v);

    // Initialize the graph as a list of lists, each representing adjacency list of a node
    g = vector<vector<int>>(n);

    // Read edges to construct the graph
    read_edges(v);

    // Initialize distance arrays to -1, will be populated during DFS
    ta_dist = vector<int>(n, -1);
    ao_dist = vector<int>(n, -1);

    // Start DFS from Ao to compute distances
    ao_dfs_start(ao);

    // Start DFS from Ta to compute distances
    ta_dfs_start(ta);

    // Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
    find_max_dist();

    // Print the result, which is the maximum distance minus one
    cout << res - 1 << endl;

    return 0;
}

