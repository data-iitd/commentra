// Including the 'iostream' header for input/output operations
#include <iostream>

// Function declaration for finding the minimum number among given integers
int min(int nums[], int n) {
	// Initializing the minimum value with the first integer
	int min = nums[0];

	// Iterating through the array 'nums' to find the minimum value
	for (int i = 1; i < n; i++) {
		// If the current value is less than the minimum value, update the minimum value
		if (nums[i] < min) {
			min = nums[i];
		}
	}

	// Returning the minimum value
	return min;
}

// Main function declaration
int main() {
	// Declaring three integer variables for reading input values
	int n, a, b;

	// Reading input values from the standard input using 'cin' object
	std::cin >> n >> a >> b;

	// Printing the minimum value between 'n*a' and 'b' using 'cout' object
	std::cout << min(n*a, b) << std::endl;

	// End of the code
	return 0;
}

// End of the code
