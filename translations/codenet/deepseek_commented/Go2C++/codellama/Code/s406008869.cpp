
#include <iostream>
#include <vector>

using namespace std;

// Function to print the edges of the graph in a readable format
void printEdge(vector<vector<int>> e) {
	for (int i = 1; i < n + 1; i++) {
		cout << i << ": ";
		for (int j = 0; j < e[i].size(); j++) {
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
}

// Depth-First Search (DFS) function to count connected components in the graph
int dfs(int v, vector<bool> &visited) {
	// Mark the current node as visited
	// cout << v << " " << visited << endl;

	// Check if all nodes are visited
	bool comp = true;
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			comp = false;
		}
	}

	if (comp) {
		return 1;
	}

	int count = 0;
	for (int i = 0; i < e[v].size(); i++) {
		// cout << "ne=" << e[v][i] << endl;
		if (visited[e[v][i]]) {
			continue;
		}
		visited[e[v][i]] = true;
		// if (cmp, _ := dfs(e[v][i], visited, count); cmp) {
		// 	count++;
		// }
		count += dfs(e[v][i], visited);
		visited[e[v][i]] = false;
	}
	return count;
}

// Main function to read input, initialize the graph, and perform DFS
int main() {
	cin >> n >> m;

	// Initialize the graph edges
	vector<vector<int>> e(n + 1);
	for (int i = 1; i < n + 1; i++) {
		e[i] = vector<int>();
	}

	// Read the edges and populate the graph
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	// printEdge(e);

	// Initialize visited slice and start DFS from node 1
	vector<bool> visited(n + 1);
	visited[1] = true;
	int count = dfs(1, visited);
	cout << count << endl;

	return 0;
}

