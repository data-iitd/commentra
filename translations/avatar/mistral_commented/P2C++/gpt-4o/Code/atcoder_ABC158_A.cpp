#include <iostream>
#include <string>

int main() {
    // Read a line from the standard input
    std::string s;
    std::getline(std::cin, s);

    // Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
    std::string result = (s.find('A') != std::string::npos && s.find('B') != std::string::npos) ? "Yes" : "No";

    // Print the value of the variable result
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
