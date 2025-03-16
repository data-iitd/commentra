#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    char d = 'a' - 'A';

    for (char& r : s) {
        if (r >= 'A' && r <= 'Z') {
            r += d;
        } else if (r >= 'a' && r <= 'z') {
            r -= d;
        }
        std::cout << r;
    }

    std::cout << std::endl;

    return 0;
}
