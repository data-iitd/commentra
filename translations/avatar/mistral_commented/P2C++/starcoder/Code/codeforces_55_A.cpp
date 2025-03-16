
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n % 2 == 0) {
        n /= 2;
    }

    if (n == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

