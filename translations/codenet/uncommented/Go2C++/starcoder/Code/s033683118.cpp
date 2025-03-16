#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k, x;
	cin >> k >> x;

	string ans = "No";
	if (k * 500 >= x) {
		ans = "Yes";
	}
	cout << ans << endl;
}

