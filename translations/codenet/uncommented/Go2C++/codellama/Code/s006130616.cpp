#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<int>> a(n);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		a[i] = vector<int>(m);
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 1200001;
	int tot = 0;
	bool ok = true;
	vector<int> skill(m);
	for (int bits = 0; bits < (1 << n); bits++) {
		tot = 0;
		ok = true;
		skill = vector<int>(m);
		for (int i = 0; i < n; i++) {
			if (bits & (1 << i)) {
				tot += p[i];
				for (int j = 0; j < m; j++) {
					skill[j] += a[i][j];
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (skill[i] < x) {
				ok = false;
				break;
			}
		}

		if (ok) {
			if (ans > tot) {
				ans = tot;
			}
		}
	}

	if (ans != 1200001) {
		cout << ans << endl;
	} else {
		cout << "-1" << endl;
	}

	return 0;
}

