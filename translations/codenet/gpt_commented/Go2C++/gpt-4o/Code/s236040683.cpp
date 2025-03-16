#include <iostream>
#include <vector>

using namespace std;

// Node represents a graph node with a vector of connected nodes.
struct Node {
    vector<int> to; // Vector to hold indices of connected nodes
};

int main() {
    int N, M;
    cin >> N >> M; // Read the number of nodes (N) and edges (M)

    // Create a vector of Node structures to represent the graph
    vector<Node> n(N);

    // Read M edges and populate the graph
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to; // Read the edge endpoints (1-indexed)
        from--; // Convert to 0-indexed
        to--;   // Convert to 0-indexed
        n[from].to.push_back(to); // Add the connection from 'from' to 'to'
        n[to].to.push_back(from); // Add the connection from 'to' to 'from' (undirected graph)
    }

    // Output the degree (number of connections) of each node
    for (int i = 0; i < N; i++) {
        cout << n[i].to.size() << endl; // Print the number of connections for node i
    }

    return 0;
}

// <END-OF-CODE>
