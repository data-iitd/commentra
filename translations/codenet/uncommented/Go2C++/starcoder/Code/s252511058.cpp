#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> points(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i].first;
		int L;
		cin >> L;
		points[i].second = points[i].first - L;
	}
	sort(points.begin(), points.end());
	int start = points[0].second;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (points[i].first < start) continue;
		start = points[i].second;
		ans++;
	}
	cout << ans << endl;
}

