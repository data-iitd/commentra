
#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

// Main method starts the execution of the program
int main() {
    // Read the number of nodes N from the standard input
    int N;
    cin >> N;
    // Read the indices u and v of the two nodes from the standard input
    int u, v;
    cin >> u >> v;

    // Initialize the adjacency lists for the graph
    vector<list<int>> edges(N);

    // Read the edges of the graph from the standard input and add them to the adjacency lists
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        // Add the edge between nodes a and b to both adjacency lists
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    // Initialize the distance arrays d and e for depth-first search
    vector<int> d(N, INT_MAX);
    vector<int> e(N, INT_MAX);

    // Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
    dfs(u - 1, d, edges);
    dfs(v - 1, e, edges);

    // Find the maximum difference between the distances of any node from u and v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Print the result: the maximum difference between the distances of any node from u and v
    if (q <= 0) {
        cout << 0 << endl;
    } else {
        cout << q - 1 << endl;
    }

    return 0;
}

// Depth-first search recursive helper method
void dfs(int u, vector<int>& d, vector<list<int>>& edges) {
    for (int nu : edges[u]) {
        if (d[nu] == INT_MAX) {
            // Mark the current node as visited and update the distance of its neighbors
            d[nu] = d[u] + 1;
            dfs(nu, d, edges);
        }
    }
}

