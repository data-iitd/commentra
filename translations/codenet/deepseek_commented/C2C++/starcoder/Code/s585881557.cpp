#include <iostream>  // Include the standard input-output library

int main(void) {  // Define the main function, the entry point of the program
	int h, r;  // Declare two integer variables
	std::cin >> h >> r;  // Read two integers from the standard input and store them in h and r
	if (r > -h) {  // Check if r is greater than -h
		std::cout << "1\n";  // If true, print 1
	} else if (r == -h) {  // If the condition in the if statement is false, check if r is equal to -h
		std::cout << "0\n";  // If true, print 0
	} else {  // If neither of the above conditions is true
		std::cout << "-1\n";  // Print -1
	}
	return 0;  // Return 0, indicating successful execution
}
