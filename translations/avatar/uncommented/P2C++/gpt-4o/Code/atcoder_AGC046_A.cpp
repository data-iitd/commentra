#include <iostream>
#include <numeric> // for std::gcd

int main() {
    int x;
    std::cin >> x;
    std::cout << 360 / std::gcd(360, x) << std::endl;
    return 0;
}

// <END-OF-CODE>
