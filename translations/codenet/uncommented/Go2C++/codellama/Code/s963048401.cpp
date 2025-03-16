
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int as[n];
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}
	int xs[n];
	xs[0] = as[0];
	for (int j = 1; j < n; j++) {
		int idx = lower_bound(xs, xs + n, as[j]) - xs;
		if (idx == n) {
			xs[n] = as[j];
		} else {
			xs[idx] = as[j];
		}
	}
	cout << n << endl;
	return 0;
}

