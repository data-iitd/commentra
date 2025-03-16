
#include <stdio.h> // Include the standard input/output library

int main() {
	int a; // Declare an integer variable 'a' to store user input
	scanf("%d", &a); // Read an integer value from standard input and store it in 'a'

	// Calculate the area of a circle with radius 'a' using the formula: Area = 3 * a^2
	printf("%d\n", 3 * a * a); // Print the calculated area to the standard output

	return 0; // Return 0 to indicate successful execution of the program
}
