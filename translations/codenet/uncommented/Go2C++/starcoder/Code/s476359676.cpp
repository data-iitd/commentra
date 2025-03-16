#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	int aPrev = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		switch {
		case a > i || a > aPrev + 1:
			cout << -1 << endl;
			return 0;
		case a == aPrev + 1:
			ans++;
		default:
			ans += a;
		}
		aPrev = a;
	}
	cout << ans << endl;
	return 0;
}

