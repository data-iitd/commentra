#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i, r = i + 1;
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}
		ans++;
		i = r;
	}
	cout << ans << endl;
	return 0;
}

