#include <stdio.h>

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
	scanf("%d %d %d", &n, &a, &b); // Read three integers from input

	printf("%d\n", min(n*a, b)); // Print the minimum of n*a and b
}

