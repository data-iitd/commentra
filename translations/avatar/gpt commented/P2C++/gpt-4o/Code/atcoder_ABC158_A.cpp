#include <iostream>
#include <string>

int main() {
    // Read input from the standard input (user input)
    std::string s;
    std::getline(std::cin, s);

    // Check if both 'A' and 'B' are present in the input string
    // If both are found, set result to "Yes", otherwise set it to "No"
    std::string result = (s.find('A') != std::string::npos && s.find('B') != std::string::npos) ? "Yes" : "No";

    // Print the result indicating whether both 'A' and 'B' were found
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
