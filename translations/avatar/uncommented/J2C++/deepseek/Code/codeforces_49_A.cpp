#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int length = s.length();
    char ch = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '?') {
            ch = s[i];
            break;
        }
    }
    ch = std::tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
