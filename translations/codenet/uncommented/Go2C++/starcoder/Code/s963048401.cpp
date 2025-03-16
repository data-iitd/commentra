#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> xs = {a[0]};
	for (int j = 1; j < n; j++) {
		int idx = lower_bound(xs.begin(), xs.end(), a[j]) - xs.begin();
		if (idx == xs.size()) {
			xs.push_back(a[j]);
		} else {
			xs[idx] = a[j];
		}
	}
	cout << xs.size() << endl;
	return 0;
}
