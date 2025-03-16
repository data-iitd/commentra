#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string output;
    char ch;

    while (ss >> std::noskipws >> ch) {
        if (ch == ',') {
            output += ' ';
        } else {
            output += ch;
        }
    }

    std::cout << output << std::endl;

    return 0;
}
