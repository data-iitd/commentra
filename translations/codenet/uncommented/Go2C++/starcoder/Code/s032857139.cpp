
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;

int n, x;
int A[1000010];

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A, A + n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
		} else {
			break;
		}
	}
	if (ans == n && x > 0) {
		ans--;
	}
	cout << ans << endl;
}

