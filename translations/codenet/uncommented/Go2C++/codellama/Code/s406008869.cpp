#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> e;

void printEdge(vector<vector<int>> e) {
	for (int i = 1; i < n+1; i++) {
		cout << i << ": ";
		for (int j = 0; j < e[i].size(); j++) {
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
}

int dfs(int v, vector<bool> visited) {
	// visited[v] = true
	// cout << v << " " << visited << endl;

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
	for (int i = 0; i < e[v].size(); i++) {
		// cout << "ne=" << e[v][i] << endl;
		if (visited[e[v][i]]) {
			continue;
		}
		visited[e[v][i]] = true;
		// if (cmp, _ := dfs(e[v][i], visited, count); cmp) {
		// 	count++;
		// }
		int rst = dfs(e[v][i], visited);
		// cout << rst << endl;
		// count += dfs(e[v][i], visited);
		count += rst;
		visited[e[v][i]] = false;
	}
	return count;
}

int main() {
	cin >> n >> m;

	e = vector<vector<int>>(n+1);
	for (int i = 1; i < n+1; i++) {
		e[i] = vector<int>();
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	// printEdge(e);

	vector<bool> visited(n+1);
	visited[1] = true;
	int count = dfs(1, visited);
	cout << count << endl;

	return 0;
}

