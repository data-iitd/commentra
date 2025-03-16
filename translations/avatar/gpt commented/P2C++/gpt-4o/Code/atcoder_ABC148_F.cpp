#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

// Define a large prime number for modular arithmetic
const int mod = 1e9 + 7;

// Define infinity for comparison purposes
const int INF = numeric_limits<int>::max();

// Function to read a single integer from input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Depth-first search (DFS) function to calculate distances
void dfs(int node, vector<int>& dist, const vector<vector<int>>& g) {
    for (int v : g[node]) {
        if (dist[v] != -1) continue; // Skip if already visited
        dist[v] = dist[node] + 1; // Update distance
        dfs(v, dist, g); // Recursive DFS call
    }
}

int main() {
    // Read the number of nodes and the starting points for ta and ao
    int n = inp();
    int ta = inp() - 1; // Adjusting to zero-based index
    int ao = inp() - 1; // Adjusting to zero-based index

    // Initialize the graph as an adjacency list
    vector<vector<int>> g(n);
    
    // Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int a = inp() - 1; // Adjusting to zero-based index
        int b = inp() - 1; // Adjusting to zero-based index
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Initialize distance arrays for ta and ao
    vector<int> ta_dist(n, -1);
    ta_dist[ta] = 0; // Distance to itself is 0
    vector<int> ao_dist(n, -1);
    ao_dist[ao] = 0; // Distance to itself is 0

    // Perform DFS from ao to calculate distances
    dfs(ao, ao_dist, g);

    // Perform DFS from ta to calculate distances
    dfs(ta, ta_dist, g);

    // Initialize result variable to track the maximum distance
    int res = 0;

    // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue; // Skip if ta is further away than ao
        res = max(res, ao_dist[i]); // Update result with the maximum distance
    }

    // Print the result, subtracting 1 to adjust for zero-based indexing
    cout << res - 1 << endl;

    return 0;
}

// <END-OF-CODE>
