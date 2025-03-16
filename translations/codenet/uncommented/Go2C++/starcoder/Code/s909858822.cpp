#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int ans;
	if (6 <= A && A <= 12) {
		ans = B / 2;
	} else if (12 < A) {
		ans = B;
	}
	cout << ans << endl;
}

