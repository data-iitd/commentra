#include <iostream>
#include <cctype>

int main() {
    int alpha[26] = {0}; // Initialize the array to zero
    char ch;

    while (true) {
        ch = std::cin.get();
        if (ch == EOF) break;

        if (std::isalpha(ch)) {
            if (std::isupper(ch)) alpha[ch - 'A']++;
            else alpha[ch - 'a']++;
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        std::cout << ch << " : " << alpha[ch - 'a'] << std::endl;
    }
}

// <END-OF-CODE>
