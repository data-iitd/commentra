#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arrA(n);
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	vector<int> cumSumA(n+1);
	cumSumA[0] = 0;
	for (int i = 0; i < n; i++) {
		cumSumA[i+1] = cumSumA[i] + arrA[i];
	}

	double ans = 10000000000.0;
	for (int i = 1; i < n; i++) {
		if (abs(double(cumSumA[n]-(cumSumA[i]*2))) < ans) {
			ans = abs(double(cumSumA[n] - cumSumA[i]*2));
		}
	}

	cout << int(ans) << endl;
}

