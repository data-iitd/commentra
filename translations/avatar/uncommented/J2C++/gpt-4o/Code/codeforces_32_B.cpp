#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;
    bool s = false;

    for (size_t i = 0; i < n.length(); i++) {
        if (n[i] == '.') {
            if (s) {
                std::cout << 1;
                s = false;
            } else {
                std::cout << 0;
            }
        } else {
            if (s) {
                std::cout << 2;
                s = false;
            } else {
                s = true;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
