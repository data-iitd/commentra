#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Declaring variables
	int a, b, ret;

	// Reading the first integer 'a' from stdin
	scanf("%d", &a);

	// Reading the second integer 'b' from stdin
	scanf("%d", &b);

	// Calculating the sum of 'a' and 'b'
	ret = a + b;

	// Checking if the sum is less than the difference of 'a' and 'b'
	if (ret < (a - b)) {
		// If true, then update the value of'ret'
		ret = a - b;
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if (ret < (a * b)) {
		// If true, then update the value of'ret'
		ret = a * b;
	}

	// Printing the final value of'ret'
	printf("%d", ret);

	// End of the code
	return 0;
}

