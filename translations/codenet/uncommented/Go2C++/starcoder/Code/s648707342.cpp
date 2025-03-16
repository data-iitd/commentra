#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; i++) {
		int x, l;
		cin >> x >> l;
		as[i] = {x - l, x + l};
	}
	sort(as.begin(), as.end());
	int ans = 1, r = as[0].second;
	for (int i = 1; i < n; i++) {
		if (as[i].first >= r) {
			ans++;
			r = as[i].second;
		}
	}
	cout << ans << endl;
}

