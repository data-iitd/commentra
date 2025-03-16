#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double ave = accumulate(a.begin(), a.end(), 0.0) / a.size();

	double minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		double diff = abs(a[i] - ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	cout << ansIndex << endl;
}

