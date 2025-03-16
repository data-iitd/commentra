#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		switch (c) {
		case 'M':
			a.push_back(1000);
			break;
		case 'A':
			a.push_back(900);
			break;
		case 'R':
			a.push_back(500);
			break;
		case 'C':
			a.push_back(400);
			break;
		case 'H':
			a.push_back(100);
			break;
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int left = 3 - i;
		for (int j = 0; j < n; j++) {
			int res = 1;
			for (int k = 0; k < left; k++) {
				res *= a[j];
			}
			ans += res;
		}
	}
	cout << ans << "\n";
}

