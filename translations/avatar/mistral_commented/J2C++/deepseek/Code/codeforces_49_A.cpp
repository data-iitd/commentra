#include <iostream>
#include <string>
#include <cctype> // for tolower()

int main() {
    std::string s;
    std::getline(std::cin, s);

    char ch = ' ';
    int length = s.length();

    for (int i = length - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '?') {
            ch = std::tolower(s[i]);
            break;
        }
    }

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
