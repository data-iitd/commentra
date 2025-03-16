#include <iostream>
#include <cmath>

int main() {
    int r, D, x;
    std::cin >> r >> D >> x;

    for (int i = 2; i <= 11; ++i) {
        int result = static_cast<int>(std::pow(r, i - 1) * (x + D / (1 - r)) - D / (1 - r));
        std::cout << result << std::endl;
    }

    return 0;
}
