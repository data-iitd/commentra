#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

int main() {
    std::string str;
    std::cin >> str;
    size_t dotIndex = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    if (str[dotIndex - 1] == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    } else if (str[dotIndex + 1] - '0' > 4) {
        std::string _str;
        for (size_t i = 0; i < dotIndex; i++) {
            _str += str[i];
        }
        std::cout << std::stoi(_str) + 1 << std::endl;
    } else {
        for (size_t i = 0; i < dotIndex; i++) {
            std::cout << str[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
