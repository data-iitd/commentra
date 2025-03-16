#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> l1;
    std::stringstream ss(input);
    int num;

    while (ss >> num) {
        l1.push_back(num);
    }

    int x1 = l1[0], y1 = l1[1];
    int x2 = l1[2], y2 = l1[3];

    int denominator = x2 - x1;
    int numerator = y2 - y1;

    if (denominator == 0) {
        int d = static_cast<int>(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)));
        int x4 = x1, x3 = x2, y3 = y2 + d, y4 = y1 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    } else {
        double quotient = static_cast<double>(numerator) / denominator;

        if (quotient == 1.0 || quotient == -1.0) {
            int x4, x3, y3, y4;
            if (quotient == 1.0) {
                x4 = x2; x3 = x1; y3 = y1; y4 = y2;
            } else {
                x4 = x1; x3 = x2; y3 = y2; y4 = y1;
            }
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }

    return 0;
}
