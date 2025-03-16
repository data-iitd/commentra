#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string output;
    while (ss >> output) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}
