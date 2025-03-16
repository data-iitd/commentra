
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> e;
int n, m;

void printEdge(vector<vector<int>> e) {
	for (int i = 1; i < n+1; i++) {
		cout << i << ": ";
		for (int v : e[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
}

int dfs(int v, vector<bool> &visited) {
	visited[v] = true;

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
		if (visited[ne]) {
			continue;
		}
		visited[ne] = true;
		count += dfs(ne, visited);
		visited[ne] = false;
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
}

