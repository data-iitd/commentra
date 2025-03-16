#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string ans = "second";
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % 2 == 1) {
			ans = "first";
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}

