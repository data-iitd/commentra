#include <iostream> // Include the standard input/output library

int main(void) { // The entry point of the program
	int h, r; // Declare two integer variables h and r
	std::cin >> h >> r; // Read two integers from the standard input and store them in variables h and r
	if(r > -h){ // Check if r is greater than the negative value of h
		std::cout << "1" << std::endl; // If the condition is true, print the number 1 followed by a newline character
	}
	else if (r == -h){ // Check if r is equal to the negative value of h
		std::cout << "0" << std::endl; // If the condition is true, print the number 0 followed by a newline character
	}
	else{ // If the previous conditions are false
		std::cout << "-1" << std::endl; // Print the number -1 followed by a newline character
	}
	return 0; // Indicate that the program has run successfully and terminate the execution
}
