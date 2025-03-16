
#include <stdio.h> // Include the standard input/output library

int main() {
	int a; // Declare an integer variable 'a' to store user input
	scanf("%d", &a); // Read an integer value from standard input and store it in 'a'
	
	// Calculate the expression a + a^2 + a^3 and print the result
	printf("%d\n", a + a*a + a*a*a); 
	
	return 0; // Return 0 to indicate successful execution
}
