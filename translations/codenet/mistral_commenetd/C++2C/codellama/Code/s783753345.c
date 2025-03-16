#include<stdio.h> // Include the standard input/output library for input and output operations
#include<string.h> // Include the string library for handling strings

int main() { // The main function is the entry point of the program
	int a, b; // Declare two integer variables 'a' and 'b'
	char S;   // Declare a character variable 'S'

	// A while loop that runs indefinitely until the user enters '?' to exit
	while (1) {
		scanf("%d %c %d", &a, &S, &b); // Read an integer 'a', a character 'S', and an integer 'b' from the standard input

		// Perform arithmetic operations based on the operator 'S'
		if (S == '+') printf("%d\n", a + b); // If 'S' is '+', print the sum of 'a' and 'b'
		if (S == '-') printf("%d\n", a - b); // If 'S' is '-', print the difference of 'a' and 'b'
		if (S == '*') printf("%d\n", a * b); // If 'S' is '*', print the product of 'a' and 'b'
		if (S == '/') printf("%d\n", a / b); // If 'S' is '/', print the quotient of 'a' and 'b'
		if (S == '?') break; // If 'S' is '?', break out of the loop
	}
}
