
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> e[100001];

void printEdge(vector<int> e[100001]) {
	for (int i = 1; i < n+1; i++) {
		cout << i << ": ";
		for (int v : e[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
}

int dfs(int v, vector<bool> &visited) {
	// Mark the current node as visited
	// cout << v << " " << visited[v] << endl;

	// Check if all nodes are visited
	bool comp = true;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			comp = false;
		}
	}

	if (comp) {
		return 1;
	}

	int count = 0;
	for (int ne : e[v]) {
		// cout << "ne=" << ne << endl;
		if (visited[ne]) {
			continue;
		}
		visited[ne] = true;
		// if (cmp, _ := dfs(ne, visited, count); cmp) {
		// 	count++;
		// }
		int rst = dfs(ne, visited);
		// cout << rst << endl;
		// count += dfs(ne, visited);
		count += rst;
		visited[ne] = false;
	}
	return count;
}

int main() {
	cin >> n >> m;

	// Initialize the graph edges
	for (int i = 1; i < n+1; i++) {
		e[i].clear();
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
	vector<bool> visited(n+1, false);
	visited[1] = true;
	int count = dfs(1, visited);
	cout << count << endl;
}

