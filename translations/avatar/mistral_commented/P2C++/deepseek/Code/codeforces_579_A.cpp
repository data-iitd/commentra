#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int x = 1;

    while (true) {
        if (std::log2(n) == static_cast<int>(std::log2(n))) {
            break;
        }

        x += 1;

        n -= std::pow(2, static_cast<int>(std::log2(n)));
    }

    std::cout << x << std::endl;

    return 0;
}
