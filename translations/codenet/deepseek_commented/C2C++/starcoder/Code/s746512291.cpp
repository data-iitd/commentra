#include<iostream>  // Include the standard input/output library

int main(void) {  // Define the main function
	int x;  // Declare an integer variable
	std::cin >> x;  // Read an integer from the user
	std::cout << x * x * x << std::endl;  // Calculate and print the cube of the input value
	return 0;  // Return from the main function
}
