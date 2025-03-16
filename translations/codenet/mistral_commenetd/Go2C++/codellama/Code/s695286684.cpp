// 2018-07-29T20:36:21+0800
#include <iostream> // Include the iostream header for formatted I/O
#include <string> // Include the string header for string manipulation

// Define a variable `s` of type `std::string` to store the user input.
std::string s;

// Read a string input from the standard input and store it in the variable `s`.
int main() {
	std::cout << "Enter a string: "; // Print a prompt message to the standard output.
	std::cin >> s; // Read a string input from the standard input and store it in the variable `s`.

	// Replace all occurrences of the string "2017" in the string `s` with the string "2018".
	s = std::string(s).replace(std::string("2017"), std::string("2018"));

	// Print the modified string to the standard output.
	std::cout << "Modified string: " << s << std::endl;

	return 0; // Return zero to indicate successful execution.
}

// End of code.


