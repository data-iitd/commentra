
// 2018-07-29T20:36:21+0800
#include <iostream> // Include the iostream library for input/output operations.
#include <string> // Include the string library for string manipulation.

// Define a variable `s` of type `std::string` to store the user input.
std::string s;

// Read a string input from the standard input and store it in the variable `s`.
int main() {
	std::cout << "Enter a string: "; // Print a prompt message to the standard output.
	std::cin >> s; // Read a string input from the standard input and store it in the variable `s`.

	// Replace all occurrences of the string "2017" in the string `s` with the string "2018".
	size_t pos = 0; // Initialize a variable `pos` to store the position of the first occurrence of the string "2017" in the string `s`.
	while ((pos = s.find("2017", pos))!= std::string::npos) { // Find the position of the first occurrence of the string "2017" in the string `s`.
		s.replace(pos, 4, "2018"); // Replace the substring starting at position `pos` with a length of 4 characters with the string "2018".
		pos += 4; // Increment the position `pos` by 4 to find the next occurrence of the string "2017" in the string `s`.
	}

	// Print the modified string to the standard output.
	std::cout << "Modified string: " << s << std::endl; // Print the modified string to the standard output.

	return 0; // Return 0 to indicate successful execution of the program.
}

// End of code.
