

#include <stdio.h>

// min function takes a variable number of integer arguments and returns the minimum value among them.
int min(int nums[], int size) {
	// Initialize min with the first element of nums
	int min = nums[0];
	// Iterate over each value in nums to find the minimum
	for (int i = 1; i < size; i++) {
		// Update min if the current value is less than the current min
		if (nums[i] < min) {
			min = nums[i];
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
	printf("%d", min(n*a, b));
}

