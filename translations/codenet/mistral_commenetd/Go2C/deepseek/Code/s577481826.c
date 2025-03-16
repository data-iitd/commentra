#include <stdio.h>
#include <stdlib.h>

// Function to read a single line from stdin
char* read() {
	static char buffer[100];
	fgets(buffer, sizeof(buffer), stdin);
	return buffer;
}

// Main function
int main() {
	// Reading the first integer 'a' from stdin
	int a;
	sscanf(read(), "%d", &a);

	// Reading the second integer 'b' from stdin
	int b;
	sscanf(read(), "%d", &b);

	// Calculating the sum of 'a' and 'b'
	int ret = a + b;

	// Checking if the sum is less than the difference of 'a' and 'b'
	if (ret < (a - b)) {
		// If true, then update the value of 'ret'
		ret = a - b;
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if (ret < (a * b)) {
		// If true, then update the value of 'ret'
		ret = a * b;
	}

	// Printing the final value of 'ret'
	printf("%d\n", ret);

	// End of the code
	return 0;
}
