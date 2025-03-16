
#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    int min_value = std::min(a, b);
    int max_value = std::max(a, b);

    std::cout << min_value << " " << static_cast<int>(std::floor((max_value - min_value) / 2.0)) << std::endl;

    return 0;
}

