
#include <iostream>
#include <algorithm>

int main() {
	// Create an array to hold three integers
	int in[3];

	// Read three integers from standard input
	std::cin >> in[0] >> in[1] >> in[2];

	// Sort the integers in ascending order
	std::sort(in, in + 3);

	// Calculate the result based on the sorted integers
	// The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
	int result = in[2] * 10 + in[1] + in[0];

	// Print the result to standard output
	std::cout << result << std::endl;

	return 0;
}
