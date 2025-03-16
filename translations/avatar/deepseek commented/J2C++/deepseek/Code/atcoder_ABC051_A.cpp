#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string word;
    while (ss >> word) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}
