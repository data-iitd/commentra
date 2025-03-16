
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; i++) {
		int x, l;
		cin >> x >> l;
		as[i] = make_pair(x - l, x + l);
	}
	sort(as.begin(), as.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	});

	int ans = 1;
	int r = as[0].second;
	for (int i = 1; i < n; i++) {
		if (as[i].first >= r) {
			ans++;
			r = as[i].second;
		}
	}
	cout << ans << endl;
	return 0;
}

