#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int price = 700;
    for (char c : s) {
        if (c == 'o') {
            price += 100;
        }
    }
    std::cout << price << std::endl;

    return 0;
}

// <END-OF-CODE>
