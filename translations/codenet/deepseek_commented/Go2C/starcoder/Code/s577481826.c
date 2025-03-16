
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	// Read the first integer from input
	int a = atoi(read());
	// Read the second integer from input
	int b = atoi(read());

	// Perform addition of the two integers
	int ret = a + b;

	// Check if the result is less than the difference between the two integers
	if (ret < (a - b)) {
		ret = a - b;
	}
	// Check if the updated result is less than the product of the two integers
	if (ret < (a * b)) {
		ret = a * b;
	}

	// Print the final result
	printf("%d", ret);
}

