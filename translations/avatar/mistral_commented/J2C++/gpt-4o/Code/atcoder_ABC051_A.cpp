#include <iostream> // Include iostream for input and output
#include <string>   // Include string for string manipulation
#include <sstream>  // Include sstream for string stream operations

int main() {
    std::string a; // Declare a string variable to store the input string

    // Read the input string from the console and store it in the 'a' variable
    std::getline(std::cin, a);

    // Replace all occurrences of ',' in the 'a' string with a single space
    for (char &c : a) {
        if (c == ',') {
            c = ' '; // Replace ',' with ' '
        }
    }

    // Print the modified string to the console
    std::cout << a << std::endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
