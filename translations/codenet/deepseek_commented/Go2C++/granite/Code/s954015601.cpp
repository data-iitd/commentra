
// 深さ優先探索
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

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
	int N;
	cin >> N;

	// Initialize a vector to store edges and an adjacency list for the graph.
	vector<vector<int>> edges(N);
	for (int i = 0; i < N - 1; i++) {
		// Read edge information and populate the adjacency list.
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// Initialize a map to store the color of each edge and a queue for DFS traversal.
	map<int, int> colors;
	queue<pair<int, int>> q;
	q.push(make_pair(0, -1));
	while (!q.empty()) {
		// Pop the last element from the queue for DFS traversal.
		int currentNode = q.front().first, usedColor = q.front().second;
		q.pop();
		int color = 1;
		for (int childNode : edges[currentNode]) {
			if (childNode == usedColor) {
				continue;
			}
			if (color == usedColor) {
				color++;
			}
			colors[genid(currentNode, childNode)] = color;
			q.push(make_pair(childNode, currentNode));
			color++;
		}
	}

	// Determine the maximum degree of any node in the graph.
	int K = -1;
	for (int i = 0; i < N; i++) {
		K = max(K, (int)edges[i].size());
	}
	cout << K << endl;

	// Output the colors of the edges.
	for (int i = 0; i < N - 1; i++) {
		cout << colors[genid(i, i + 1)] << endl;
	}
}

