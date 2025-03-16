#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// 変数未使用エラー回避
	a[0] = 0;

	int sum = k;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		sum = sum - 1 + k;
		if (sum >= n) {
			break;
		}
		ans++;
	}
	cout << ans << endl;
}

