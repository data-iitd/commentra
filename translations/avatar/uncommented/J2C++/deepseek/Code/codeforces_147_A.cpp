#include <iostream>
#include <string>
#include <cctype>

bool isLatinLetter(char c) {
    return std::islower(c) || std::isupper(c);
}

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string sb;
    int n = s.length();
    sb += s[0];
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                sb += ' ';
            }
            sb += c;
        } else if (isPunctuation(c)) {
            sb += c;
        }
    }
    std::cout << sb << std::endl;
    return 0;
}

