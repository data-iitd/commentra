#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	a[0] = 0;
	int sum = k;
	int ans = 1;
	while (sum < n) {
		sum = sum - 1 + k;
		ans++;
	}
	cout << ans << endl;
	return 0;
}

