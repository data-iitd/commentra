
#include <iostream>
#include <cmath>

int main() {
    double r, D, x;
    std::cin >> r >> D >> x;

    for (int i = 2; i <= 11; i++) {
        double result = std::pow(r, i - 1) * (x + D / (1 - r)) - D / (1 - r);
        std::cout << static_cast<int>(result) << std::endl;
    }

    return 0;
}

