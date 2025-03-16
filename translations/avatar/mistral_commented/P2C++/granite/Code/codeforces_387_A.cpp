
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    int h1 = std::stoi(input.substr(0, 2));
    int m1 = std::stoi(input.substr(3, 2));

    std::getline(std::cin, input);
    int h2 = std::stoi(input.substr(0, 2));
    int m2 = std::stoi(input.substr(3, 2));

    m1 += h1 * 60;
    m2 += h2 * 60;

    int m2_ = m1 - m2;
    m2_ %= 1440;

    std::cout << std::setfill('0') << std::setw(2) << m2_ / 60 << ":" << std::setw(2) << m2_ % 60 << std::endl;

    return 0;
}

