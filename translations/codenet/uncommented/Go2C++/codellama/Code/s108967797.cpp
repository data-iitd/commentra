
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int ri() {
	int n;
	cin >> n;
	return n;
}

double ave(vector<double> s) {
	double sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i];
	}
	return sum / s.size();
}

double diff(double a, double b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int main() {
	int n = ri();
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// cout << a << endl;

	double ave = ave(a);

	double minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		double diff = diff(a[i], ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	cout << ansIndex << endl;
	return 0;
}

