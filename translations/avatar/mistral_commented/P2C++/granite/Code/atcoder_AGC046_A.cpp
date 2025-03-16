

#include <iostream>
#include <cmath>

int main() {
    int x;
    std::cin >> x;
    int gcd_value = gcd(360, x);
    std::cout << 360 / gcd_value << std::endl;
    return 0;
}

