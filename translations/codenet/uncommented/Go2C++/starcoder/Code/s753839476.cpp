#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, t, a;
	cin >> n >> t >> a;
	vector<double> heights(n);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	double minDiff = abs(t - heights[0] * 0.006 - a);
	int minIdx = 0;
	for (int i = 0; i < n - 1; i++) {
		double diff = abs(t - heights[i + 1] * 0.006 - a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i + 1;
		}
	}
	cout << minIdx + 1 << endl;
}

