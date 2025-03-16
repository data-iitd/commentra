#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int ans = 0;
	int i = 0, j = 0;
	while (j < A.size()) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
			i++;
		} else {
			j++;
		}
	}

	if (x > 0 && A.size() == ans) {
		ans--;
	}

	cout << ans << endl;
}

