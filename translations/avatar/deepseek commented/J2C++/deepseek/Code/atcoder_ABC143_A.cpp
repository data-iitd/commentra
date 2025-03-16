#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    try {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int a, b, c;
        std::string token;
        while (std::getline(ss, token, ' ')) {
            c = a - b * 2;
            if (c < 0) c = 0;
            std::cout << c << std::endl;
        }
    } catch (const std::exception& e) {
        // Handle exceptions (not implemented in this code)
    }
    return 0;
}
