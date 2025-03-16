#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i].first >> s[i].second;
	}
	sort(s.begin(), s.end());

	int total = 0;
	for (auto e : s) {
		int n = min(e.second, M);
		total += n * e.first;
		M -= n;
		if (M == 0) {
			break;
		}
	}
	cout << total << endl;
}

