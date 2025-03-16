#include <iostream>

// min finds the smallest number among the given arguments
int min(int nums[], int n) {
	int min = nums[0]; // Initialize min with the first element
	for (int i = 1; i < n; i++) {
		if (nums[i] < min) { // Compare each element with the current min
			min = nums[i]; // Update min if a smaller value is found
		}
	}
	return min; // Return the smallest value
}

int main() {
	int n, a, b;
	std::cin >> n >> a >> b; // Read three integers from input

	std::cout << min(new int[n]{a, b}, n) << std::endl; // Print the minimum of n*a and b
}

