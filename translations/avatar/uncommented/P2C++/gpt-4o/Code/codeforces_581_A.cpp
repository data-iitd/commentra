#include <iostream>
#include <algorithm> // for std::min and std::max

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::min(a, b) << " " << (std::max(a, b) - std::min(a, b)) / 2 << std::endl;
    return 0;
}

// <END-OF-CODE>
