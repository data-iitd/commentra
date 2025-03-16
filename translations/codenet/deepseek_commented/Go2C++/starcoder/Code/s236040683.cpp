
#include <bits/stdc++.h>

using namespace std;

// Node :
struct Node {
	vector<int> to;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Read the number of nodes (N) and the number of edges (M)
	int N, M;
	cin >> N >> M;

	// Initialize a vector of Node with N elements
	vector<Node> n(N);

	// Read M pairs of edges and populate the adjacency list for each node
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		n[from-1].to.push_back(to-1);
		n[to-1].to.push_back(from-1);
	}

	// Print the size of the adjacency list for each node
	for (int i = 0; i < N; i++) {
		cout << n[i].to.size() << endl;
	}
}

