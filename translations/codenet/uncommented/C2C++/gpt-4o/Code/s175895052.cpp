#include <iostream>
#include <cstring>

int main() {
    char n[10];
    std::cin >> n;
    if (((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3]))) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
