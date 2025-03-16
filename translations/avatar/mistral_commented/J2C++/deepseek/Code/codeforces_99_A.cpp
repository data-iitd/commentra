#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

int main() {
    std::string str;
    std::cin >> str;

    int dotIndex = -1;

    // Finding the index of the last occurrence of '.' character in the string
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dotIndex = i;
        }
    }

    // Checking if the character before the '.' character is '9'
    if (str[dotIndex - 1] == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    }

    // Checking if the character after the '.' character is a digit greater than 4
    else if (str[dotIndex + 1] - '0' > 4) {
        std::string _str = str.substr(0, dotIndex);

        // Performing big integer addition and printing the result
        int carry = 1;
        for (int i = _str.length() - 1; i >= 0; i--) {
            int digit = _str[i] - '0' + carry;
            if (digit == 10) {
                _str[i] = '0';
            } else {
                _str[i] = '0' + digit;
                carry = 0;
                break;
            }
        }
        if (carry == 1) {
            _str = '1' + _str;
        }
        std::cout << _str << std::endl;
    }

    // Printing the substring of the character array str from the beginning to the index of '.' character
    else {
        std::cout << str.substr(0, dotIndex) << std::endl;
    }

    return 0;
}
