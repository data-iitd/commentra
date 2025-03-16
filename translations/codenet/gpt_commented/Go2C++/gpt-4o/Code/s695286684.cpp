#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation

// Main function where the execution of the program begins
int main() {
    std::string s; // Declare a variable 's' to hold the input string

    // Read a string input from the user and store it in variable 's'
    std::cin >> s;

    // Replace all occurrences of "2017" with "2018" in the input string and print the result
    size_t pos = 0;
    while ((pos = s.find("2017", pos)) != std::string::npos) {
        s.replace(pos, 4, "2018"); // Replace "2017" with "2018"
        pos += 4; // Move past the last replaced substring
    }
    
    std::cout << s << std::endl; // Print the modified string
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
