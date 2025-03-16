#include <stdio.h>  // Include the stdio library for input and output operations
#include <string.h> // Include the string library for handling strings

int main() { // The main function is the entry point of the program
	int a, b; // Declare two integer variables 'a' and 'b'
	char S[2]; // Declare a character array 'S' to hold the operator

	// A while loop that runs indefinitely until the user enters '?' to exit
	while (1) {
		scanf("%d %s %d", &a, S, &b); // Read an integer 'a', a string 'S', and an integer 'b' from the standard input

		// Perform arithmetic operations based on the operator 'S'
		if (strcmp(S, "+") == 0) printf("%d\n", a + b); // If 'S' is '+', print the sum of 'a' and 'b'
		if (strcmp(S, "-") == 0) printf("%d\n", a - b); // If 'S' is '-', print the difference of 'a' and 'b'
		if (strcmp(S, "*") == 0) printf("%d\n", a * b); // If 'S' is '*', print the product of 'a' and 'b'
		if (strcmp(S, "/") == 0) printf("%d\n", a / b); // If 'S' is '/', print the quotient of 'a' and 'b'
		if (strcmp(S, "?") == 0) break; // If 'S' is '?', break out of the loop
	}
}
