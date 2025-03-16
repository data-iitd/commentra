#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n; // Reading the size of the array

	vector<int> arrA(n);
	for (int i = 0; i < n; i++) {
		cin >> arrA[i]; // Reading the elements of the array
	}

	vector<int> cumSumA(n+1);
	cumSumA[0] = 0; // Initialize the cumulative sum array
	for (int i = 0; i < n; i++) {
		cumSumA[i+1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
	}

	double ans = 10000000000.0; // Initialize the answer with a large number
	for (int i = 1; i < n; i++) {
		if (abs(double(cumSumA[n]-(cumSumA[i]*2))) < ans) {
			ans = abs(double(cumSumA[n] - cumSumA[i]*2)); // Update the answer if a smaller difference is found
		}
	}

	cout << int(ans) << endl; // Output the minimum difference
}

