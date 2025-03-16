

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read two integers from input and convert them from string to int
	int a, b;
	scanf("%d %d", &a, &b);

	// Initialize ret with the sum of a and b
	int ret = a + b;

	// Check if ret is less than the difference of a and b
	if (ret < (a - b)) {
		ret = a - b; // Update ret to the difference if it's smaller
	}
	// Check if ret is less than the product of a and b
	if (ret < (a * b)) {
		ret = a * b; // Update ret to the product if it's smaller
	}

	// Print the final result
	printf("%d", ret);
	return 0;
}

