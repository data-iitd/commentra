#include <stdio.h>
#include <stdlib.h>

// Function to read a line of input and return it as a string
char* read() {
	static char buffer[1000];
	fgets(buffer, sizeof(buffer), stdin);
	return buffer;
}

int main() {
	// Read two integers from input and convert them from string to int
	int a, b;
	sscanf(read(), "%d", &a); // Read first integer
	sscanf(read(), "%d", &b); // Read second integer

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
	printf("%d\n", ret);

	return 0;
}
