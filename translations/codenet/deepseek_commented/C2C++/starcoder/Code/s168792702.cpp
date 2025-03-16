#include <iostream>  // Include the standard input/output library

int main(void) {  // Define the main function, the entry point of the program
	int a, b, c;  // Declare three integer variables
	std::cin >> a >> b >> c;  // Read three integers from the user and store them in variables a, b, and c
	
	if (a < b && b < c) std::cout << "Yes";  // Check if a is less than b and b is less than c, and print "Yes" if true
	else std::cout << "No";  // Print "No" if the condition is not met
	
	return 0;  // Return 0 to indicate successful execution
}
