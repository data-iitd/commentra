#include <iostream>
#include <string>

int main() {
    // Ask the user for a string input
    std::string s;
    std::getline(std::cin, s);

    // Initialize an empty string variable to store the binary string
    std::string my_str = "";

    // Iterate through each character in the user input string
    for (char c : s) {
        // If the character is '0' or '1', append it to the binary string
        if (c == '0' || c == '1') {
            my_str += c;
        }
        // If the character is 'B', remove the last character from the binary string before 'B' was encountered
        else if (c == 'B' && !my_str.empty()) {
            my_str.pop_back();
        }
    }

    // Print the final binary string
    std::cout << my_str << std::endl;

    return 0;
}

// <END-OF-CODE>
