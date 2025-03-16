
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> edges(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	map<int, int> colors;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, -1, -1));
	while (!q.empty()) {
		int currentNode, usedColor, parentNode;
		tie(currentNode, usedColor, parentNode) = q.front();
		q.pop();
		int color = 1;
		for (int childNode : edges[currentNode]) {
			if (childNode == parentNode) {
				continue;
			}
			if (color == usedColor) {
				color++;
			}
			colors[genid(currentNode, childNode)] = color;
			q.push(make_tuple(childNode, color, currentNode));
			color++;
		}
	}

	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = edges[i].size();
		if (t > K) {
			K = t;
		}
	}
	cout << K << endl;

	for (int i = 0; i < N - 1; i++) {
		cout << colors[genid(ab[i][0], ab[i][1])] << endl;
	}
}

