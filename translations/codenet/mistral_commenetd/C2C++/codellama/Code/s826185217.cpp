#include <iostream> // Include the standard input/output library

int main(void){ // Define the main function with no arguments
	int a, b, c, d; // Declare four integer variables

	std::cin >> a >> b >> c >> d; // Read four integers from the standard input and store them in the variables a, b, c, and d

	if (a + b > c + d) { // Check if the sum of a and b is greater than the sum of c and d
		std::cout << "Left\n"; // If true, print "Left" to the standard output
	} else if (a + b < c + d) { // Check if the sum of a and b is less than the sum of c and d
		std::cout << "Right\n"; // If true, print "Right" to the standard output
	} else { // If neither of the above conditions is true
		std::cout << "Balanced\n"; // Print "Balanced" to the standard output
	}

	return 0; // Indicate that the program has run successfully
}

