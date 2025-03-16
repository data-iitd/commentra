
#include <bits/stdc++.h>

using namespace std;

// Define a large prime number for modular arithmetic
const int mod = 1000000007;

// Define infinity for comparison purposes
const int INF = 1e9;

// Function to read a single integer from input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> inpl() {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        v.push_back(inp());
    }
    return v;
}

// Function to perform depth-first search (DFS)
void dfs(vector<vector<int>> &g, vector<int> &dist, int node, int par) {
    for (int v : g[node]) {
        if (v == par) {
            continue;  // Skip if parent
        }
        if (dist[v] != -1) {
            continue;  // Skip if already visited
        }
        dist[v] = dist[node] + 1;  // Update distance
        dfs(g, dist, v, node);  // Recursive DFS call
    }
}

// Function to perform breadth-first search (BFS)
void bfs(vector<vector<int>> &g, vector<int> &dist, int node) {
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int v : g[node]) {
            if (dist[v] != -1) {
                continue;  // Skip if already visited
            }
            dist[v] = dist[node] + 1;  // Update distance
            q.push(v);  // Enqueue for BFS
        }
    }
}

int main() {
    // Read the number of nodes and the starting points for ta and ao
    vector<int> v = inpl();
    int n = v[0], ta = v[1], ao = v[2];
    ta--;  // Adjusting to zero-based index
    ao--;  // Adjusting to zero-based index

    // Initialize the graph as an adjacency list
    vector<vector<int>> g(n);

    // Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        v = inpl();
        g[v[0] - 1].push_back(v[1] - 1);  // Adjusting to zero-based index
        g[v[1] - 1].push_back(v[0] - 1);  // Adjusting to zero-based index
    }

    // Initialize distance arrays for ta and ao
    vector<int> ta_dist(n, -1);
    ta_dist[ta] = 0;  // Distance to itself is 0
    vector<int> ao_dist(n, -1);
    ao_dist[ao] = 0;  // Distance to itself is 0

    // Perform BFS from ao to calculate distances
    bfs(g, ao_dist, ao);

    // Perform BFS from ta to calculate distances
    bfs(g, ta_dist, ta);

    // Initialize result variable to track the maximum distance
    int res = 0;

    // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) {
            continue;  // Skip if ta is further away than ao
        }
        res = max(res, ao_dist[i]);  // Update result with the maximum distance
    }

    // Print the result, subtracting 1 to adjust for zero-based indexing
    cout << res - 1 << endl;

    return 0;
}

