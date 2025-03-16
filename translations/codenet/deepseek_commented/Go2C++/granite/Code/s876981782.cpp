
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int N;
	std::cin >> N; // Read the number of values
	std::vector<double> values(N);
	for (int i = 0; i < N; i++) {
		std::cin >> values[i]; // Read the values into the vector
	}

	std::sort(values.begin(), values.end()); // Sort the values in ascending order
	double generated = 0;
	//std::cout << values << std::endl; // Uncomment to print the sorted values (for debugging purposes)
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2; // Calculate the average of the current and next value
		values[i+1] = generated; // Update the next value with the calculated average
	}

	std::cout << generated << std::endl; // Print the final generated value
}

