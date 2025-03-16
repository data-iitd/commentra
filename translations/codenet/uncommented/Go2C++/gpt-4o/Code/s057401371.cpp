#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    char d = 'a' - 'A';
    for (char r : s) {
        char rr = r;
        if ('A' <= r && r <= 'Z') {
            rr = r + d;
        } else if ('a' <= r && r <= 'z') {
            rr = r - d;
        }
        std::cout << rr;
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
