
#include <bits/stdc++.h>
using namespace std;

// Define a large prime number for modular arithmetic
const int mod = 1e9 + 7;

// Define infinity for comparison purposes
const int INF = 1e9;

// Function to read a single integer from input
int inp() { 
    int x; 
    cin >> x; 
    return x;
}

// Function to read a list of integers from input
vector<int> inpl(int n) { 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    return a;
}

// Read the number of nodes and the starting points for ta and ao
int n, ta, ao;
cin >> n >> ta >> ao;
ta--;  // Adjusting to zero-based index
ao--;  // Adjusting to zero-based index

// Initialize the graph as an adjacency list
vector<vector<int>> g(n);

// Read the edges of the graph and populate the adjacency list
for (int i = 0; i < n - 1; i++) {
    int a, b; 
    cin >> a >> b; 
    a--;  // Adjusting to zero-based index
    b--;  // Adjusting to zero-based index
    g[a].push_back(b);  // Populate adjacency list
    g[b].push_back(a);  // Populate adjacency list
}

// Initialize distance arrays for ta and ao
vector<int> ta_dist(n, -1);
vector<int> ao_dist(n, -1);

// Depth-first search (DFS) function to calculate distances from ta
void ta_dfs(int node) {
    for (int v : g[node]) {
        if (ta_dist[v]!= -1) continue;  // Skip if already visited
        ta_dist[v] = ta_dist[node] + 1;  // Update distance
        ta_dfs(v);  // Recursive DFS call
    }
}

// Depth-first search (DFS) function to calculate distances from ao
void ao_dfs(int node) {
    for (int v : g[node]) {
        if (ao_dist[v]!= -1) continue;  // Skip if already visited
        ao_dist[v] = ao_dist[node] + 1;  // Update distance
        ao_dfs(v);  // Recursive DFS call
    }
}

// Perform DFS from ao to calculate distances
ao_dist[ao] = 0;  // Distance to itself is 0
ao_dfs(ao);

// Perform DFS from ta to calculate distances
ta_dist[ta] = 0;  // Distance to itself is 0
ta_dfs(ta);

// Initialize result variable to track the maximum distance
int res = 0;

// Calculate the maximum distance where ta's distance is less than or equal to ao's distance
for (int i = 0; i < n; i++) {
    if (ta_dist[i] > ao_dist[i]) continue;  // Skip if ta is further away than ao
    res = max(res, ao_dist[i]);  // Update result with the maximum distance
}

// Print the result, subtracting 1 to adjust for zero-based indexing
cout << res - 1 << endl;  // Print the result

