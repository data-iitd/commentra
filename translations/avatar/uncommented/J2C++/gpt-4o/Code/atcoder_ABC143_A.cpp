#include <iostream>
#include <sstream>
#include <string>

int main() {
    try {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        int a, b;
        iss >> a >> b;
        int c = a - b * 2;
        if (c < 0) c = 0;
        std::cout << c << std::endl;
    } catch (...) {
        // Handle exceptions if necessary
    }
    return 0;
}

// <END-OF-CODE>
