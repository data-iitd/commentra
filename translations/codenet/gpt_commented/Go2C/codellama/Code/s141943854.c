
#include <stdio.h>
#include <stdlib.h>

// check is a utility function that logs an error and exits the program if an error is encountered.
void check(int e) {
	if (e != 0) {
		printf("error: %d\n", e);
		exit(1);
	}
}

int main() {
	// Create a new scanner to read input from standard input (stdin).
	char sage[100];
	scanf("%s", sage);

	// Use a switch statement to handle different cases based on the input value.
	switch (atoi(sage)) {
	case 1:
		// If the input is "1", print "Hello World".
		printf("Hello World\n");
		break;
	case 2:
		// If the input is "2", initialize a variable to hold the sum of two numbers.
		int sum = 0;
		// Loop to read two numbers from input.
		for (int i = 0; i < 2; i++) {
			scanf("%d", &sum);
		}
		// Print the total sum of the two numbers.
		printf("%d\n", sum);
		break;
	}
	return 0;
}

