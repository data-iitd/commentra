
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read the number of elements in the array from the input
	int N;
	cin >> N;

	// Allocate memory for two arrays X and Y of size N
	vector<int> X(N);
	vector<int> Y(N);

	// Read N integers from the input and store them in X and Y arrays
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		// Store the current element of X in Y array for sorting
		Y[i] = X[i];
	}

	// Sort the Y array in ascending order
	sort(Y.begin(), Y.end());

	// Find the median of Y array
	int m1 = Y[N/2 - 1];
	int m2 = Y[N/2];

	// Iterate through each element of X array and print the corresponding median value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			// If X[i] is smaller than m1, print m2 as the answer
			cout << m2 << endl;
		} else {
			// If X[i] is greater than m1, print m1 as the answer
			cout << m1 << endl;
		}
	}
}

