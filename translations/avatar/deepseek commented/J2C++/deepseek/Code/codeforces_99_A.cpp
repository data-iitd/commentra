#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string str;
    std::cin >> str;

    // Find the index of the dot ('.') in the string
    size_t dotIndex = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    // Check if the character before the dot is '9'
    if (str[dotIndex - 1] == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    }
    // If the character before the dot is not '9', check the digit after the dot
    else if (str[dotIndex + 1] - '0' > 4) {
        // Increment the number before the dot by 1 and print the result
        std::string _str = "";
        for (size_t i = 0; i < dotIndex; i++) {
            _str += str[i];
        }
        int num = std::stoi(_str) + 1;
        std::cout << std::to_string(num) << std::endl;
    }
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else {
        for (size_t i = 0; i < dotIndex; i++) {
            std::cout << str[i];
        }
        std::cout << std::endl;
    }

    return 0;
}

