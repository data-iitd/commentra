#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i*i < n; i++) {
		if (n%i == 0 && n%(n/i-1) == i) {
			ans += n/i - 1;
		}
	}
	cout << ans << endl;
}

