#include <iostream>
#include <string>

int main() {
    // Read input string from the user
    std::string str;
    std::getline(std::cin, str);

    // Find the index of the dot ('.') in the string
    size_t dotIndex = str.find('.');
    
    // Check if the character before the dot is '9'
    if (str[dotIndex - 1] == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    }
    // If the character before the dot is not '9', check the digit after the dot
    else if (str[dotIndex + 1] > '4') {
        // Increment the number before the dot by 1 and print the result
        std::string beforeDot = str.substr(0, dotIndex);
        std::cout << std::stoll(beforeDot) + 1 << std::endl;
    }
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else {
        std::cout << str.substr(0, dotIndex) << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
