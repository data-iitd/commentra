#include <iostream>  // Include the iostream library for input and output
#include <string>    // Include the string library to use the string class

int main() {
    std::string stdin;  // Declare a string variable to store user input
    std::getline(std::cin, stdin);  // Take input from the user and store it in the variable stdin

    std::string s = stdin;  // Assign the input to the variable s

    // Check if the string s contains both "A" and "B"
    std::string result;  // Declare a string variable to store the result
    if (s.find("A") != std::string::npos && s.find("B") != std::string::npos) {
        result = "Yes";  // If both "A" and "B" are in the string, set result to "Yes"
    } else {
        result = "No";   // Otherwise, set result to "No"
    }

    std::cout << result << std::endl;  // Print the result

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
