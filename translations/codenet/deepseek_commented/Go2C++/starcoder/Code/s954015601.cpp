
#include <bits/stdc++.h>

using namespace std;

// genid generates a unique identifier for an edge between two nodes.
int genid(int a, int b) {
	if (b < a) {
		swap(a, b);
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes from standard input.
	int N = readInt();

	// Initialize a slice to store edges and an adjacency list for the graph.
	vector<vector<int>> edges(N);
	vector<pair<int, int>> ab(N-1);
	for (int i = 0; i < N-1; i++) {
		// Read edge information and populate the adjacency list.
		int a = readInt() - 1;
		int b = readInt() - 1;
		ab[i] = {a, b};
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// Initialize a map to store the color of each edge and a queue for DFS traversal.
	map<int, int> colors;
	queue<pair<int, int>> q;
	q.push({0, -1});
	while (!q.empty()) {
		// Pop the last element from the queue for DFS traversal.
		int currentNode, parentNode;
		tie(currentNode, parentNode) = q.front();
		q.pop();
		int color = 1;
		for (int childNode : edges[currentNode]) {
			if (childNode == parentNode) {
				continue;
			}
			if (color == colors[genid(currentNode, childNode)]) {
				color++;
			}
			colors[genid(currentNode, childNode)] = color;
			q.push({childNode, currentNode});
			color++;
		}
	}

	// Determine the maximum degree of any node in the graph.
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = edges[i].size();
		if (t > K) {
			K = t;
		}
	}
	cout << K << endl;

	// Output the colors of the edges.
	for (int i = 0; i < N-1; i++) {
		cout << colors[genid(ab[i].first, ab[i].second)] << endl;
	}
}

