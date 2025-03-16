#include <iostream>
#include <cmath>
#include <vector>

int main() {
    std::string given;
    std::getline(std::cin, given);
    
    std::vector<int> l1;
    std::istringstream iss(given);
    int number;
    while (iss >> number) {
        l1.push_back(number);
    }

    int x1 = l1[0];
    int y1 = l1[1];
    int x2 = l1[2];
    int y2 = l1[3];

    int denominator = x2 - x1;
    int numerator = y2 - y1;
    double quotient;

    if (denominator != 0) {
        quotient = static_cast<double>(numerator) / denominator;
    }

    if (numerator == 0) {
        int d = static_cast<int>(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        int x4 = x1;
        int x3 = x2;
        int y3 = y2 + d;
        int y4 = y1 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    } else if (denominator == 0) {
        int y4 = y2;
        int y3 = y1;
        int d = static_cast<int>(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        int x4 = x1 + d;
        int x3 = x2 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    } else if (denominator != 0 && numerator != 0) {
        if (quotient == 1) {
            int x4 = x2;
            int x3 = x1;
            int y4 = y1;
            int y3 = y2;
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        } else if (quotient == -1) {
            int x4 = x1;
            int x3 = x2;
            int y4 = y2;
            int y3 = y1;
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
