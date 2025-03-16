
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t, a;
	cin >> n >> t >> a;

	vector<double> heights(n);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	double minDiff = abs(t - heights[0] * 0.006 - a);
	int minIdx = 0;
	for (int i = 1; i < n; i++) {
		double diff = abs(t - heights[i] * 0.006 - a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
	}
	cout << minIdx + 1 << endl;

	return 0;
}

