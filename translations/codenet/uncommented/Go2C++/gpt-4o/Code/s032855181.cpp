#include <iostream>
#include <string>

std::string group(int n) {
    if (n == 4 || n == 6 || n == 9 || n == 11) {
        return "B";
    } else {
        return "A";
    }
}

int main() {
    int x, y;
    std::cin >> x >> y;

    if (x == 2 || y == 2) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::string xg = group(x);
    std::string yg = group(y);

    if (xg == yg) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
