// Include the "stdio.h" header file for formatted I/O
#include <stdio.h>

int main() {
	// Declare and initialize three integer variables "a", "b", and "c"
	// with values read from the standard input using the scanf function
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	// Check if the condition "a < b && b < c" is true using an if statement
	if (a < b && b < c) {
		// If the condition is true, print the string "Yes" to the standard output
		printf("Yes\n");
	} else {
		// If the condition is false, print the string "No" to the standard output
		printf("No\n");
	}

	// Return from the main function
	return 0;
}

// End of code 