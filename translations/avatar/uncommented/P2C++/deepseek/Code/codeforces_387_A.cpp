#include <iostream>
#include <string>
#include <sstream>

int main() {
    int h1, m1, h2, m2;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss1(input);
    std::getline(ss1, input, ':');
    h1 = std::stoi(input);
    std::getline(ss1, input);
    m1 = std::stoi(input);
    m1 += h1 * 60;

    std::getline(std::cin, input);
    std::stringstream ss2(input);
    std::getline(ss2, input, ':');
    h2 = std::stoi(input);
    std::getline(ss2, input);
    m2 = std::stoi(input);
    m2 += h2 * 60;

    m2 = m1 - m2;
    m2 %= 1440;

    std::cout << std::format("{:02d}:{:02d}", m2 / 60, m2 % 60) << std::endl;
    return 0;
}
