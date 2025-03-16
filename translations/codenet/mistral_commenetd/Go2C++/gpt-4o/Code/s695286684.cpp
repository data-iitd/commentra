// 2018-07-29T20:36:21+0800
#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation

// Define a variable `s` of type `std::string` to store the user input.
std::string s;

// Read a string input from the standard input and store it in the variable `s`.
int main() {
    std::cout << "Enter a string: "; // Print a prompt message to the standard output.
    std::getline(std::cin, s); // Read a string input from the standard input and store it in the variable `s`.

    // Replace all occurrences of the string "2017" in the string `s` with the string "2018".
    size_t pos = 0;
    while ((pos = s.find("2017", pos)) != std::string::npos) {
        s.replace(pos, 4, "2018"); // Replace "2017" with "2018"
        pos += 4; // Move past the last replaced substring
    }

    // Print the modified string to the standard output.
    std::cout << "Modified string: " << s << std::endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
