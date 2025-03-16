#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read the number of values to be processed
	int N;
	cin >> N;

	// Initialize a vector to hold the float values
	vector<float> values(N);

	// Read N float values from standard input
	for (int i = 0; i < N; i++) {
		cin >> values[i];
	}

	// Sort the vector of float values in ascending order
	sort(values.begin(), values.end());

	// Variable to hold the generated average value
	float generated;

	// Calculate the average of each pair of adjacent values
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2;
		// Update the next value in the vector with the generated average
		values[i+1] = generated;
	}

	// Print the last generated average value
	cout << generated << endl;

	return 0;
}

