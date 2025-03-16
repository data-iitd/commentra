#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

// Function to read a single integer from input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> inpl() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return a;
}

int main() {
    // Set the recursion limit to a high value to handle deep recursions
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of nodes and the starting points for ta and ao
    int n, ta, ao;
    cin >> n >> ta >> ao;
    --ta;  // Adjusting to zero-based index
    --ao;  // Adjusting to zero-based index

    // Initialize the graph as an adjacency list
    vector<vector<int>> g(n);

    // Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;  // Adjusting to zero-based index
        --b;  // Adjusting to zero-based index
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Initialize distance arrays for ta and ao
    vector<int> ta_dist(n, INF);
    vector<int> ao_dist(n, INF);
    ta_dist[ta] = 0;  // Distance to itself is 0
    ao_dist[ao] = 0;  // Distance to itself is 0

    // Breadth-first search (BFS) function to calculate distances from ta
    queue<int> q;
    q.push(ta);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int v : g[node]) {
            if (ta_dist[v] != INF) continue;  // Skip if already visited
            ta_dist[v] = ta_dist[node] + 1;  // Update distance
            q.push(v);  // Push to queue for further exploration
        }
    }

    // Breadth-first search (BFS) function to calculate distances from ao
    queue<int> q2;
    q2.push(ao);
    while (!q2.empty()) {
        int node = q2.front();
        q2.pop();
        for (int v : g[node]) {
            if (ao_dist[v] != INF) continue;  // Skip if already visited
            ao_dist[v] = ao_dist[node] + 1;  // Update distance
            q2.push(v);  // Push to queue for further exploration
        }
    }

    // Initialize result variable to track the maximum distance
    int res = 0;

    // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
    for (int i = 0; i < n; ++i) {
        if (ta_dist[i] > ao_dist[i]) continue;  // Skip if ta is further away than ao
        res = max(res, ao_dist[i]);  // Update result with the maximum distance
    }

    // Print the result, subtracting 1 to adjust for zero-based indexing
    cout << res - 1 << '\n';

    return 0;
}
