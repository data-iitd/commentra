#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    if (n % k == 0) std::cout << "0\n";
    else std::cout << "1\n";
    return 0;
}

// <END-OF-CODE>
