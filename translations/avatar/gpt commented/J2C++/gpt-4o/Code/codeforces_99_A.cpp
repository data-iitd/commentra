#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    // Read input from the user
    std::string str;
    std::getline(std::cin, str);
    
    // Initialize variable to store the index of the decimal point
    size_t dotIndex = str.find('.');

    // Check if the digit before the decimal point is '9'
    if (str[dotIndex - 1] == '9') {
        // If it is, print a specific message
        std::cout << "GOTO Vasilisa." << std::endl;
    }
    // Check if the digit after the decimal point is greater than 4
    else if (std::atoi(str.substr(dotIndex + 1, 1).c_str()) > 4) {
        // If it is, create a new string from the integer part and add 1
        std::string integerPart = str.substr(0, dotIndex);
        // Print the incremented value
        std::cout << std::stoll(integerPart) + 1 << std::endl;
    }
    // If the digit after the decimal point is 4 or less
    else {
        // Print the integer part as it is
        std::cout << str.substr(0, dotIndex) << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
