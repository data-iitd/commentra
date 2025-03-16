
#include <iostream>

// min finds the smallest number among the given arguments
int min(int n, int a, int b) {
	int min = n * a; // Initialize min with the product of n and a
	if (b < min) { // Compare b with the current min
		min = b; // Update min if b is smaller
	}
	return min; // Return the smallest value
}

int main() {
	int n, a, b;
	std::cin >> n >> a >> b; // Read three integers from input

	std::cout << min(n, a, b) << std::endl; // Print the minimum of n, a, and b

	return 0;
}


