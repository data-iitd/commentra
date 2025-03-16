#include<iostream> // Including the standard input/output library

int main(){ // Starting the main function
	int x; // Declaring an integer variable x

	std::cin >> x; // Reading an integer value from the user and storing it in variable x

	// The following block of code calculates x raised to the power of 3
	x = x * x * x;

	// Printing the result to the console
	std::cout << x << std::endl;

	return 0; // Indicating successful execution of the program
}

