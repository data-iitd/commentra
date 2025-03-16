#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b;
	for (int i = 0; i < n; i++) {
		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (x == b.size()) {
			b.push_back(a[i]);
		} else {
			b[x] = a[i];
		}
	}

	cout << b.size() << endl;

	return 0;
}

