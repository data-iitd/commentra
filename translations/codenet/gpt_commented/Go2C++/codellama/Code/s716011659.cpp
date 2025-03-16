
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	// Read the number of elements in the array
	int n;
	cin >> n;

	// Initialize an array to hold the input values
	int arrA[n];
	// Read the input values into the array
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	// Create a cumulative sum array to store the cumulative sums of arrA
	int cumSumA[n+1];
	cumSumA[0] = 0; // The first element is 0 (sum of zero elements)
	// Calculate the cumulative sums
	for (int i = 0; i < n; i++) {
		cumSumA[i+1] = cumSumA[i] + arrA[i];
	}

	// Initialize the answer variable to a large value
	double ans = 10000000000.0;
	// Iterate through the cumulative sums to find the minimum difference
	for (int i = 1; i < n; i++) {
		// Calculate the absolute difference between the total sum and twice the current cumulative sum
		if (abs(cumSumA[n]-(cumSumA[i]*2)) < ans) {
			// Update the answer if the current difference is smaller
			ans = abs(cumSumA[n] - cumSumA[i]*2);
		}
	}

	// Print the final answer as an integer
	cout << int(ans) << endl;

	return 0;
}

