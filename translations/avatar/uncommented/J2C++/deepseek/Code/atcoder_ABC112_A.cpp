#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input

    if (n == 1) {
        std::cout << "Hello World" << std::endl;
    } else {
        std::string line1, line2;
        std::getline(std::cin, line1);
        std::getline(std::cin, line2);
        int sum = std::stoi(line1) + std::stoi(line2);
        std::cout << sum << std::endl;
    }

    return 0;
}
