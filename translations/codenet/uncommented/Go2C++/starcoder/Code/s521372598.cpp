#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> xs(n);
	for (int i = 0; i < n; i++) xs[i] = a[i] - i + 1;
	sort(xs.begin(), xs.end());
	int b = xs[n / 2];
	int ans = 0;
	for (int x : xs) ans += abs(x - b);
	cout << ans << "\n";
}

