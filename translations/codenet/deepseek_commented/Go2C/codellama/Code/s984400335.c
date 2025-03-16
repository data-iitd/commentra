#include <stdio.h>

// min finds the smallest number among the given arguments
int min(int nums, ...) {
	int min = nums; // Initialize min with the first element
	for (int i = 0; i < nums; i++) {
		int v = va_arg(nums, int); // Compare each element with the current min
		if (v < min) { // Update min if a smaller value is found
			min = v;
		}
	}
	return min; // Return the smallest value
}

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b); // Read three integers from input

	printf("%d\n", min(n*a, b)); // Print the minimum of n*a and b

	return 0;
}

