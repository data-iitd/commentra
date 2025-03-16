#include <stdio.h>

int main() {
	int a; // Declare a variable 'a' of type int to store user input
	scanf("%d", &a); // Read an integer value from standard input and store it in 'a'

	// Calculate the area of a circle with radius 'a' using the formula: Area = 3 * a^2
	printf("%d\n", 3 * a * a); // Print the calculated area to the standard output

	return 0;
}
