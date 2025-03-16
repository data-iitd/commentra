
#include <bits/stdc++.h>

using namespace std;

// <START-OF-CODE>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string S;
	int x, y;

	cin >> S >> x >> y;

	vector<int> F;
	int cur = 0;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'F') {
			cur++;
		} else {
			F.push_back(cur);
			cur = 0;
		}
	}
	F.push_back(cur);

	vector<int> evens, odds;
	for (int i = 0; i < F.size(); i++) {
		if (i % 2 == 0) {
			evens.push_back(F[i]);
		} else {
			odds.push_back(F[i]);
		}
	}

	vector<vector<bool>> dpx(evens.size() + 1, vector<bool>(18000 + 1, false));
	vector<vector<bool>> dpy(odds.size() + 1, vector<bool>(18000 + 1, false));

	dpx[0][10000] = true;
	dpy[0][10000] = true;

	for (int i = 0; i < evens.size(); i++) {
		int val = evens[i];
		for (int j = 2000; j <= 18000; j++) {
			if (j + val <= 18000) {
				dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
			}
			if (j - val >= 2000 && i!= 0) {
				dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
			}
		}
	}

	for (int i = 0; i < odds.size(); i++) {
		int val = odds[i];
		for (int j = 2000; j <= 18000; j++) {
			if (j + val <= 18000) {
				dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
			}
			if (j - val >= 2000) {
				dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
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