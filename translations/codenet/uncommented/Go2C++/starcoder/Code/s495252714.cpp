#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int ans = 0;
	sort(c.begin(), c.end());

	for (int i = 0; i < n; i++) {
		ans = (ans + (n - i) * c[i]) % 1000000007;
	}

	cout << (ans * pow(4, n - 1) % 1000000007) << endl;
	return 0;
}

