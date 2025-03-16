
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// out is a helper function to print output to the console.
void out(int x) {
	cout << x << endl;
}

// Create a new scanner to read input from standard input.
string getString() {
	string s;
	cin >> s;
	return s;
}

// Create a new scanner to read input from standard input.
int getInt() {
	int i;
	cin >> i;
	return i;
}

// Node represents a graph node with a slice of connected nodes.
struct Node {
	vector<int> to; // Slice to hold indices of connected nodes
};

int main() {
	// Set the scanner to split input by whitespace
	// Read the number of nodes (N) and edges (M) from input
	int N, M;
	cin >> N >> M;
	// Create a slice of Node structures to represent the graph
	vector<Node> n(N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		n[from-1].to.push_back(to-1); // Add the connection from 'from' to 'to'
		n[to-1].to.push_back(from-1); // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to.size()); // Print the number of connections for node i
	}
	return 0;
}

