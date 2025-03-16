#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s;
    std::cin >> s;

    char c = 'a';
    std::unordered_set<char> charSet(s.begin(), s.end());

    for (int j = 0; j < 26; j++) {
        if (charSet.find(c) == charSet.end()) {
            std::cout << c << std::endl;
            return 0;
        }
        c++;
    }

    std::cout << "None" << std::endl;

    return 0;
}

// <END-OF-CODE>
