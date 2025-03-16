#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> aa(n);

	for (int i = 0; i < n; i++) {
		cin >> aa[i];
	}

	vector<int> cumsum(n+1);
	cumsum[0] = 0;
	for (int i = 0; i < n; i++) {
		cumsum[i+1] = cumsum[i] + aa[i];
	}

	//cout << cumsum << endl;

	int ans = 2020202020;
	for (int i = 1; i < n-1; i++) {
		ans = min(ans, abs(cumsum[n-1]-cumsum[i]-(cumsum[i]-cumsum[0])));
	}

	cout << ans << endl;

}

