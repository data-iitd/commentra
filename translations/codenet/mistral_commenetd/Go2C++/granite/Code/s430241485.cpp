
#include <iostream> // Include the "iostream" library for input/output operations

int main(){ // Define the main function, entry point of our program
	// Declare two variables, s and t, both of type string
	std::string s, t;

	// Use the "std::cin" object to read input from the standard input (keyboard)
	// and store it in variables s and t respectively
	std::cin >> s >> t;

	// Print the concatenated string of t and s using the "std::cout" object
	std::cout << t + s << std::endl; // Use "std::endl" to insert a new line after the output

	return 0; // Return 0 to indicate successful execution of the program
}

