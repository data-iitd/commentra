// by syu
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    if (n % k == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
