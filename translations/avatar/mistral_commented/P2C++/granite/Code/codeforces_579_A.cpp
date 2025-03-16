
#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int x = 1;
    while (true) {
        if (std::log2(n) == std::floor(std::log2(n))) {
            break;
        }
        x++;
        n -= std::pow(2, std::floor(std::log2(n)));
    }

    std::cout << x << std::endl;

    return 0;
}

