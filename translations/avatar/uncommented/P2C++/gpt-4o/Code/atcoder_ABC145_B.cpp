#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    if (n % 2 != 0) {
        std::cout << "No" << std::endl;
    } else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
