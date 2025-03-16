
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// <START-OF-CODE>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string S;
	cin >> S;

	int x, y;
	cin >> x >> y;

	int n = S.size();

	vector<int> evens, odds;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			evens.push_back(int(S[i] - '0'));
		} else {
			odds.push_back(int(S[i] - '0'));
		}
	}

	vector<vector<bool>> dpx(n + 1, vector<bool>(20000, false));
	vector<vector<bool>> dpy(n + 1, vector<bool>(20000, false));

	for (int i = 0; i < evens.size(); i++) {
		for (int j = 2000; j <= 18000; j++) {
			if (j + evens[i] <= 18000) {
				dpx[i + 1][j + evens[i]] = dpx[i + 1][j + evens[i]] || dpx[i][j];
			}
			if (j - evens[i] >= 2000 && i!= 0) {
				dpx[i + 1][j - evens[i]] = dpx[i + 1][j - evens[i]] || dpx[i][j];
			}
		}
	}

	for (int i = 0; i < odds.size(); i++) {
		for (int j = 2000; j <= 18000; j++) {
			if (j + odds[i] <= 18000) {
				dpy[i + 1][j + odds[i]] = dpy[i + 1][j + odds[i]] || dpy[i][j];
			}
			if (j - odds[i] >= 2000) {
				dpy[i + 1][j - odds[i]] = dpy[i + 1][j - odds[i]] || dpy[i][j];
			}
		}
	}

	if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}

// 