
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for errors and exit with error message if any
void check(int e) {
	if (e != 0) {
		printf("error: %d\n", e);
		exit(1);
	}
}

// Main function
int main() {
	// Initialize a variable named 'sage' to store the first line read from standard input
	char sage[100];

	// Read the first line from standard input
	fgets(sage, 100, stdin);

	// Use a switch statement to determine the action based on the first line read
	switch (atoi(sage)) {
	case 1:
		// Print "Hello World" if the first line is "1"
		printf("Hello World\n");
		break;
	case 2:
		// Initialize a variable named 'sum' to store the sum of two numbers
		int sum = 0;

		// Use a for loop to read and sum two numbers
		for (int i = 0; i < 2; i++) {
			// Read the next line from standard input
			fgets(sage, 100, stdin);

			// Convert the next line to an integer and store it in a variable named 'num'
			int num = atoi(sage);

			// Check for errors and exit with error message if any
			check(num);

			// Add the current number to the sum
			sum += num;
		}

		// Print the sum of the two numbers
		printf("%d\n", sum);
		break;
	}

	// End of code
	return 0;
}

// End of code