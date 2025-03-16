#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b;
	for (int v : a) {
		int x = lower_bound(b.begin(), b.end(), v) - b.begin();
		if (x == b.size()) {
			b.push_back(v);
		} else {
			b[x] = v;
		}
	}

	cout << b.size() << endl;
}

