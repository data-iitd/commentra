#include <iostream>
#include <string>

int main() {
    // Read input from the user
    std::string s;
    std::getline(std::cin, s);

    // Initialize an empty string to store the resulting characters
    std::string my_str = "";

    // Iterate through each character in the input string
    for (char c : s) {
        // Check if the character is '0' or '1'
        if (c == '0' || c == '1') {
            // If it is, append it to the result string
            my_str += c;
        }
        // Check if the character is 'B' and the result string is not empty
        else if (c == 'B' && !my_str.empty()) {
            // If it is, remove the last character from the result string
            my_str.pop_back();
        }
    }

    // Print the final result string
    std::cout << my_str << std::endl;

    return 0;
}

// <END-OF-CODE>
