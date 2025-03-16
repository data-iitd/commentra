#include <iostream>
#include <cmath>

int main() {
    double r;
    std::cin >> r;
    double area = r * r * M_PI;
    double circumference = 2 * M_PI * r;
    std::cout << area << " " << circumference << std::endl;
    return 0;
}

