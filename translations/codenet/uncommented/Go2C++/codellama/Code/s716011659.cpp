
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arrA[n];
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	int cumSumA[n+1];
	cumSumA[0] = 0;
	for (int i = 0; i < n; i++) {
		cumSumA[i+1] = cumSumA[i] + arrA[i];
	}

	double ans = 10000000000.0;
	for (int i = 1; i < n; i++) {
		if (abs(cumSumA[n] - cumSumA[i]*2) < ans) {
			ans = abs(cumSumA[n] - cumSumA[i]*2);
		}
	}

	cout << int(ans) << endl;

	return 0;
}

