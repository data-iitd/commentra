// 深さ優先探索
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int genid(int a, int b) {
	if (b < a) {
		a = b;
		b = a;
	}
	return a * 100000 + b;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> edges(N);
	vector<vector<int>> ab(N - 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		ab[i][0] = a - 1;
		ab[i][1] = b - 1;
		edges[a - 1].push_back(b - 1);
		edges[b - 1].push_back(a - 1);
	}

	map<int, int> colors;
	vector<vector<int>> q;
	q.push_back({ 0, -1, -1 });
	while (!q.empty()) {
		int currentNode = q.back()[0];
		int usedColor = q.back()[1];
		int parentNode = q.back()[2];
		q.pop_back();
		int color = 1;
		for (int childNode : edges[currentNode]) {
			if (childNode == parentNode) {
				continue;
			}
			if (color == usedColor) {
				color++;
			}
			colors[genid(currentNode, childNode)] = color;
			q.push_back({ childNode, color, currentNode });
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

