#include <iostream>
#include <cmath>

int main() {
    int r, D, x;
    std::cin >> r >> D >> x;

    for (int i = 2; i < 12; i++) {
        int result = static_cast<int>((pow(r, i - 1) * (x + static_cast<double>(D) / (1 - r)) - static_cast<double>(D) / (1 - r)));
        std::cout << result << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
