#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, int d[], vector<int> edges[]) {
    for (int nu : edges[u]) {
        if (d[nu] == INT_MAX) { // If the node has not been visited
            d[nu] = d[u] + 1; // Update the distance
            dfs(nu, d, edges); // Recursively visit the next node
        }
    }
}

int main() {
    int N, u, v;
    cin >> N >> u >> v;
    u--; // Convert to zero-based index
    v--; // Convert to zero-based index
    
    vector<int> edges[N];
    for (int i = 0; i < N; i++) {
        edges[i] = vector<int>();
    }
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        edges[a].push_back(b); // Add edge from a to b
        edges[b].push_back(a); // Add edge from b to a (undirected graph)
    }
    
    int d[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX; // Set initial distances to infinity
    }
    d[u] = 0; // Distance to itself is 0
    
    dfs(u, d, edges);
    
    int e[N];
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX; // Set initial distances to infinity
    }
    e[v] = 0; // Distance to itself is 0
    
    dfs(v, e, edges);
    
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) { // Check if node i is closer to u than to v
            if (e[i] > q) { // Update q if the distance to v is greater
                q = e[i];
            }
        }
    }
    
    if (q <= 0) {
        cout << 0 << endl; // If no valid distance found, print 0
    } else {
        cout << q - 1 << endl; // Print the maximum distance minus 1
    }
    
    return 0;
}

