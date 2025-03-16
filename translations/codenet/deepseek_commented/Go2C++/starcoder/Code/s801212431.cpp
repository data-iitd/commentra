#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;

	// Initialize counters for '0's and '1's
	int l0 = 0, l1 = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0') {
			l0++;
		} else {
			l1++;
		}
	}
	cout << 2 * min(l0, l1) << endl;
}

