#include <iostream> // Include the standard input/output library

int main(void) // The entry point of the program
{
	int a, b, c, i, count; // Declare variables a, b, c, i, and count
	std::cin >> a >> b >> c; // Read three integers a, b, and c from the standard input
	count = 0; // Initialize the count variable to zero

	// The following for loop iterates from the value of 'a' to the value of 'b'
	for (i = a; i <= b; i++ ){
		// Check if 'c' is divisible by 'i'
		if (c % i == 0)
			// If it is, increment the count variable
			count++;
	}

	// Print the value of 'count' to the standard output
	std::cout << count << std::endl;

	// Return 0 to indicate successful execution of the program
	return 0;
}

