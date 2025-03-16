#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> n(N);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		n[from].push_back(to);
		n[to].push_back(from);
	}

	for (int i = 0; i < N; i++) {
		cout << n[i].size() << endl;
	}
}

