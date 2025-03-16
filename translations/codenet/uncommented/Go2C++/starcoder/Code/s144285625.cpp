#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> ar(3 * n);
	for (int i = 0; i < 3 * n; i++) {
		cin >> ar[i];
	}
	sort(ar.begin(), ar.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ar[3 * n - (i + 1) * 2];
	}
	cout << sum << endl;
}

