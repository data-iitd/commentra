#include <iostream>
#include <string>
#include <cctype>

bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string result;
    int n = s.length();

    if (n > 0) {
        result += s[0]; // Append the first character
    }

    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                result += ' '; // Add space if the previous character is not a Latin letter
            }
            result += c; // Append the Latin letter
        } else if (isPunctuation(c)) {
            result += c; // Append punctuation
        }
    }

    std::cout << result << std::endl;
    return 0;
}

// <END-OF-CODE>
