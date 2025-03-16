
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for errors and exit with error message if any
void check(char *message) {
	if (message!= NULL) {
		fprintf(stderr, "error: %s\n", message);
		exit(1);
	}
}

// Main function
int main(int argc, char *argv[]) {
	// Initialize a variable named'sage' to store the first line read from standard input
	char *sage = NULL;

	// Read the first line from standard input
	sage = fgets(sage, 100, stdin);

	// Check for errors and exit with error message if any
	check(sage);

	// Use a switch statement to determine the action based on the first line read
	if (strcmp(sage, "1\n") == 0) {
		// Print "Hello World" if the first line is "1"
		printf("Hello World\n");
	} else if (strcmp(sage, "2\n") == 0) {
		// Initialize a variable named'sum' to store the sum of two numbers
		int sum = 0;

		// Use a for loop to read and sum two numbers
		for (int i = 0; i < 2; i++) {
			// Initialize a variable named 'num' to store the next line read from standard input
			char *num = NULL;

			// Read the next line from standard input
			num = fgets(num, 100, stdin);

			// Check for errors and exit with error message if any
			check(num);

			// Convert the next line to an integer and store it in a variable named 'num'
			int num_int = atoi(num);

			// Add the current number to the sum
			sum += num_int;
		}

		// Print the sum of the two numbers
		printf("%d\n", sum);
	}

	// Free the memory allocated to'sage'
	free(sage);

	// Return from main
	return 0;
}

// End of code

