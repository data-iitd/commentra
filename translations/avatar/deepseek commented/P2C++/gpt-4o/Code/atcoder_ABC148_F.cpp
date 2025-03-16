#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int MOD = 1e9 + 7;

void ta_dfs(int node, vector<int>& ta_dist, const vector<vector<int>>& g) {
    for (int v : g[node]) {
        if (ta_dist[v] != -1) continue; // If already visited, skip
        ta_dist[v] = ta_dist[node] + 1; // Update distance
        ta_dfs(v, ta_dist, g); // Recursively visit neighbors
    }
}

void ao_dfs(int node, vector<int>& ao_dist, const vector<vector<int>>& g) {
    for (int v : g[node]) {
        if (ao_dist[v] != -1) continue; // If already visited, skip
        ao_dist[v] = ao_dist[node] + 1; // Update distance
        ao_dfs(v, ao_dist, g); // Recursively visit neighbors
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ta, ao;
    cin >> n >> ta >> ao;

    // Adjust indices to be zero-based
    ta--;
    ao--;

    // Initialize the graph as an adjacency list
    vector<vector<int>> g(n);
    
    // Read edges to construct the graph
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1); // Append the zero-based index of the neighbor
        g[b - 1].push_back(a - 1); // Append the zero-based index of the neighbor
    }

    // Initialize distance arrays to -1, will be populated during DFS
    vector<int> ta_dist(n, -1);
    ta_dist[ta] = 0; // Distance from Ta to Ta is 0
    vector<int> ao_dist(n, -1);
    ao_dist[ao] = 0; // Distance from Ao to Ao is 0

    // Start DFS from Ao to compute distances
    ao_dfs(ao, ao_dist, g);

    // Start DFS from Ta to compute distances
    ta_dfs(ta, ta_dist, g);

    // Initialize result variable
    int res = 0;

    // Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue; // Skip if Ta's distance is greater
        res = max(res, ao_dist[i]); // Update result with the maximum distance
    }

    // Print the result, which is the maximum distance minus one
    cout << res - 1 << endl;

    return 0;
}

// <END-OF-CODE>
