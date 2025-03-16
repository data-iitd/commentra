#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::replace(input.begin(), input.end(), ',', ' ');
    std::cout << input << std::endl;
    return 0;
}

// <END-OF-CODE>
