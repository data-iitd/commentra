#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	vector<bool> good(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		good[i] = true;
	}
	for (int i = 0; i < m; i++) {
		int ai, bi;
		cin >> ai >> bi;
		ai--;
		bi--;
		if (h[ai] > h[bi]) {
			good[bi] = false;
		} else if (h[ai] < h[bi]) {
			good[ai] = false;
		} else {
			good[ai] = false;
			good[bi] = false;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++;
		}
	}
	cout << ans << endl;
}

