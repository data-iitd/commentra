#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    for (size_t i = 0; i < s.length(); i++) {
        std::cout << "x";
    }
    std::cout << std::endl;
    return 0;
}

// <END-OF-CODE>
