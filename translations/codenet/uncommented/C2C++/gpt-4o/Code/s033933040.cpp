#include <iostream>

int main() {
    int a, b, mawari, menseki;

    std::cin >> a >> b;
    mawari = a + a + b + b;
    menseki = a * b;
    std::cout << menseki << " " << mawari << std::endl;

    return 0;
}

// <END-OF-CODE>
