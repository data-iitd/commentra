#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // Initialize the scanner to read input
    int N;
    int u;
    int v;
    cin >> N >> u >> v;
    
    // Create an adjacency list to represent the edges of the graph
    vector<int> *edges = new vector<int>[N];
    for (int i = 0; i < N; i++) {
        edges[i] = vector<int>();
    }
    
    // Read the edges and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a;
        int b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1); // Add edge from a to b
        edges[b - 1].push_back(a - 1); // Add edge from b to a (undirected graph)
    }
    
    // Initialize distance array for the first node (u)
    int *d = new int[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX; // Set initial distances to infinity
    }
    d[u - 1] = 0; // Distance to itself is 0
    
    // Perform DFS from node u to calculate distances
    dfs(u - 1, d, edges);
    
    // Initialize distance array for the second node (v)
    int *e = new int[N];
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX; // Set initial distances to infinity
    }
    e[v - 1] = 0; // Distance to itself is 0
    
    // Perform DFS from node v to calculate distances
    dfs(v - 1, e, edges);
    
    // Find the maximum distance from node u to any node that is closer to v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) { // Check if node i is closer to u than to v
            if (e[i] > q) { // Update q if the distance to v is greater
                q = e[i];
            }
        }
    }
    
    // Output the result based on the maximum distance found
    if (q <= 0) {
        cout << 0; // If no valid distance found, print 0
    } else {
        cout << q - 1; // Print the maximum distance minus 1
    }
    
    return 0;
}

// Depth-first search (DFS) to calculate distances from a given node
void dfs(int u, int *d, vector<int> *edges) {
    for (int nu : edges[u]) {
        if (d[nu] == INT_MAX) { // If the node has not been visited
            d[nu] = d[u] + 1; // Update the distance
            dfs(nu, d, edges); // Recursively visit the next node
        }
    }
}

