#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            // Process the token
            std::cout << token << std::endl;
        }
    }
    return 0;
}
