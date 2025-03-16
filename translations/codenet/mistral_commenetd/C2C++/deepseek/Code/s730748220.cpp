#include <iostream> // Standard Input/Output stream library
#include <cstdlib> // Standard Library for memory allocation and other functions
#include <climits> // Library for working with maximum and minimum values
#include <cmath> // Library for mathematical functions

int main(){
	// Declare variables
	int i,j,k,n;

	std::cout << "Enter the value of n: "; // Print a message to the console
	std::cin >> n; // Read an integer value from the user and store it in variable n

	// Calculate and print the result
	std::cout << "The result is: " << 24 + (24-n) << std::endl;

	return 0; // Indicate successful execution of the program
}

