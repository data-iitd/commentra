#include <stdio.h>

// min function takes a variable number of integer arguments and returns the minimum value among them.
int min(int nums, ...) {
	// Initialize min with the first element of nums
	int min = nums;
	// Iterate over each value in nums to find the minimum
	for (int i = 1; i < nums; i++) {
		// Update min if the current value is less than the current min
		if (va_arg(nums, int) < min) {
			min = va_arg(nums, int);
		}
	}
	// Return the minimum value found
	return min;
}

int main() {
	// Declare variables to hold input values
	int n, a, b;
	// Read three integers from standard input
	scanf("%d %d %d", &n, &a, &b);

	// Calculate the minimum of n*a and b, and print the result
	printf("%d\n", min(n*a, b));

	// End of code
	return 0;
}