#include <iostream>
#include <string>
#include <vector>

int main() {
    // Get the input string from the user
    std::string input;
    std::getline(std::cin, input);

    // Split the input string using '.' as delimiter
    size_t pos = input.find('.');
    std::string s = input.substr(0, pos);
    std::string p = input.substr(pos + 1);

    // Get the last character of the string 's'
    char last_char = s[s.length() - 1];

    // Check if the last character of the string 's' is '9'
    if (last_char == '9') {
        // If yes, print the message "GOTO Vasilisa."
        std::cout << "GOTO Vasilisa." << std::endl;
    }
    // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
    else if (last_char != '9' && (p[0] - '0') < 5) {
        // Print the string 's'
        std::cout << s << std::endl;
    }
    // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
    else {
        // Increment the last character of the string 's' by 1
        s = s.substr(0, s.length() - 1) + std::to_string((last_char - '0') + 1);
        // Print the updated string 's'
        std::cout << s << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
