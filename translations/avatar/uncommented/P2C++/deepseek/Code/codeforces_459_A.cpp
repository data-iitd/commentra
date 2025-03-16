#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

int main() {
    std::string given;
    std::getline(std::cin, given);
    std::istringstream iss(given);
    std::vector<int> l1;
    std::string token;
    while (std::getline(iss, token, ' ')) {
        l1.push_back(std::stoi(token));
    }

    int x1 = l1[0];
    int y1 = l1[1];
    int x2 = l1[2];
    int y2 = l1[3];

    int denominator = x2 - x1;
    int numerator = y2 - y1;

    if (denominator != 0) {
        double quotient = static_cast<double>(numerator) / denominator;
        if (quotient == 1) {
            int x3 = x1;
            int y3 = y2;
            int x4 = x2;
            int y4 = y1;
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        } else if (quotient == -1) {
            int x3 = x2;
            int y3 = y1;
            int x4 = x1;
            int y4 = y2;
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        }
    } else {
        int d = static_cast<int>(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)));
        int x4 = x1 + d;
        int y4 = y1 + d;
        int x3 = x2 + d;
        int y3 = y2 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    }

    if (numerator == 0) {
        int d = static_cast<int>(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)));
        int x4 = x1;
        int x3 = x2;
        int y3 = y2 + d;
        int y4 = y1 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    }

    if (denominator == 0 && numerator == 0) {
        std::cout << "-1" << std::endl;
    }

    return 0;
}
