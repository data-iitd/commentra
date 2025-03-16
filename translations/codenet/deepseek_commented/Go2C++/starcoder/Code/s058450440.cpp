#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[5] = {0};
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
		case 'M':
			a[0]++;
			break;
		case 'A':
			a[1]++;
			break;
		case 'R':
			a[2]++;
			break;
		case 'C':
			a[3]++;
			break;
		case 'H':
			a[4]++;
			break;
		}
	}

	int ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				ans += a[i] * a[j] * a[k];
			}
		}
	}
	cout << ans << "\n";
}

