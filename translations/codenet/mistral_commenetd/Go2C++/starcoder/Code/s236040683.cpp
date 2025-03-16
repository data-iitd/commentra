
#include <bits/stdc++.h>

using namespace std;

// Node is a custom data structure for representing a node in the graph.
struct Node {
	vector<int> to;
};

// out is a custom function for printing output.
void out(const vector<int> &x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

// main is the entry point of the program.
int main() {
	// Read the number of nodes N and edges M from the input.
	int N, M;
	cin >> N >> M;

	// Create a slice n of size N to store the nodes.
	vector<Node> n(N);

	// Process each edge by adding it to the to slice of the corresponding nodes.
	for (int i = 0; i < M; i++) {
		// Read the from and to nodes from the input.
		int from, to;
		cin >> from >> to;

		// Add the edge to the to slice of the from node.
		n[from-1].to.push_back(to-1);

		// Add the edge to the to slice of the to node.
		n[to-1].to.push_back(from-1);
	}

	// Print the number of neighbors for each node.
	for (int i = 0; i < N; i++) {
		// Print the number of neighbors of the current node.
		out(n[i].to);
	}
}

// 