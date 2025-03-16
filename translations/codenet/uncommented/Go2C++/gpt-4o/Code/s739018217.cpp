#include <iostream>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;
    int x = m * 1900 + (n - m) * 100;
    std::cout << x * static_cast<int>(pow(2.0, m)) << std::endl;
    return 0;
}

// <END-OF-CODE>
