
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// Initialize variables
	int N;

	// Read input: number of values
	std::cin >> N;

	// Allocate memory for N float64 values
	std::vector<float> values(N);

	// Read input: N float64 values
	for (int i = 0; i < N; i++) {
		std::cin >> values[i];
	}

	// Sort the slice in ascending order
	std::sort(values.begin(), values.end());

	// Calculate the median value
	float generated;
	// Iterate through the slice, excluding the last value (which is the maximum)
	for (int i = 0; i < N-1; i++) {
		// Calculate the average of the current and next value
		generated = (values[i] + values[i+1]) / 2;

		// Update the next value with the calculated average
		values[i+1] = generated;
	}

	// Print the calculated median value
	std::cout << generated << std::endl;
}

