#include <bits/stdc++.h>

using namespace std;

// Node represents a graph node with a slice of connected nodes.
struct Node {
	vector<int> to;
};

int main() {
	// Read the number of nodes (N) and edges (M) from input
	int N, M; cin >> N >> M;
	// Create a slice of Node structures to represent the graph
	vector<Node> n(N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from, to; cin >> from >> to;
		n[from].to.push_back(to); // Add the connection from 'from' to 'to'
		n[to].to.push_back(from); // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		cout << n[i].to.size() << endl; // Print the number of connections for node i
	}
}

