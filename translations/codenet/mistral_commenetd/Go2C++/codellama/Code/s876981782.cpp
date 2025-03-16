
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Initialize variables
	int N;

	// Read input: number of values
	cin >> N;

	// Allocate memory for N float values
	vector<float> values(N);

	// Read input: N float values
	for (int i = 0; i < N; i++) {
		cin >> values[i];
	}

	// Sort the vector in ascending order
	sort(values.begin(), values.end());

	// Calculate the median value
	float generated;
	// Iterate through the vector, excluding the last value (which is the maximum)
	for (int i = 0; i < N - 1; i++) {
		// Calculate the average of the current and next value
		generated = (values[i] + values[i + 1]) / 2;

		// Update the next value with the calculated average
		values[i + 1] = generated;
	}

	// Print the calculated median value
	cout << generated << endl;

	return 0;
}

