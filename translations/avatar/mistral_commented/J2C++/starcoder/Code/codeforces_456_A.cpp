
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int temp = 0, q = 0, w = INT_MIN, e = INT_MIN;
	bool f = false;
	for (int i = 0; i < n; i++) {
		if (temp < a[i]) {
			if (q > b[i]) {
				f = true;
			}
			q = b[i];
			temp = a[i];
		}
		if (temp > a[i]) {
			if (q < b[i]) {
				f = true;
			}
			q = b[i];
			temp = a[i];
		}
		if (a[i] > w) {
			w = a[i];
			if (b[i] < e) {
				f = true;
			}
			e = b[i];
		}
		if (a[i] < w) {
			if (b[i] > e) {
				f = true;
			}
		}
	}
	if (f) {
		cout << "Happy Alex" << endl;
	} else {
		cout << "Poor Alex" << endl;
	}
	return 0;
}

