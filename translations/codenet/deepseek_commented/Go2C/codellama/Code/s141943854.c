
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check function logs fatal errors if they occur
void check(int e) {
	if (e != 0) {
		printf("error: %d\n", e);
		exit(1);
	}
}

int main() {
	char sage[100]; // Declare sage variable to store the input
	scanf("%s", sage); // Read input from standard input

	switch (atoi(sage)) { // Convert string to integer
		case 1:
			printf("Hello World\n"); // Print "Hello World" if input is "1"
			break;
		case 2:
			int sum = 0; // Declare sum variable to store the sum of two integers
			for (int i = 0; i < 2; i++) {
				scanf("%d", &sum); // Read input from standard input
				sum += atoi(sage); // Add the integer to the sum
			}
			printf("%d\n", sum); // Print the sum of the two integers
			break;
		default:
			printf("Invalid input\n"); // Print "Invalid input" if input is not "1" or "2"
			break;
	}

	return 0;
}

