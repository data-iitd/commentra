// 深さ優先探索
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// genid generates a unique identifier for an edge between two nodes.
int genid(int a, int b) {
	if (b < a) {
		a = b;
		b = a;
	}
	return a * 100000 + b;
}

int main() {
	// Read the number of nodes from standard input.
	int N;
	cin >> N;

	// Initialize a vector to store edges and an adjacency list for the graph.
	vector<vector<int>> edges(N);
	vector<vector<int>> ab(N - 1);
	for (int i = 0; i < N - 1; i++) {
		// Read edge information and populate the adjacency list.
		int a, b;
		cin >> a >> b;
		ab[i][0] = a - 1;
		ab[i][1] = b - 1;
		edges[a - 1].push_back(b - 1);
		edges[b - 1].push_back(a - 1);
	}

	// Initialize a map to store the color of each edge and a queue for DFS traversal.
	map<int, int> colors;
	queue<vector<int>> q;
	q.push(vector<int>{0, -1, -1});
	while (!q.empty()) {
		// Pop the last element from the queue for DFS traversal.
		vector<int> currentNode = q.front();
		q.pop();
		int usedColor = currentNode[1];
		int parentNode = currentNode[2];
		int color = 1;
		for (int childNode : edges[currentNode[0]]) {
			if (childNode == parentNode) {
				continue;
			}
			if (color == usedColor) {
				color++;
			}
			colors[genid(currentNode[0], childNode)] = color;
			q.push(vector<int>{childNode, color, currentNode[0]});
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
	for (int i = 0; i < N - 1; i++) {
		cout << colors[genid(ab[i][0], ab[i][1])] << endl;
	}
	return 0;
}

