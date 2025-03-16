#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    // Replace "dream" with "D"
    size_t pos = 0;
    while ((pos = s.find("dream", pos)) != std::string::npos) {
        s.replace(pos, 5, "D");
        pos += 1; // Move past the new character
    }

    // Replace "erase" with "E"
    pos = 0;
    while ((pos = s.find("erase", pos)) != std::string::npos) {
        s.replace(pos, 5, "E");
        pos += 1; // Move past the new character
    }

    // Remove "Der"
    pos = 0;
    while ((pos = s.find("Der", pos)) != std::string::npos) {
        s.erase(pos, 3);
    }

    // Remove "Er"
    pos = 0;
    while ((pos = s.find("Er", pos)) != std::string::npos) {
        s.erase(pos, 2);
    }

    // Remove "D"
    pos = 0;
    while ((pos = s.find("D", pos)) != std::string::npos) {
        s.erase(pos, 1);
    }

    // Remove "E"
    pos = 0;
    while ((pos = s.find("E", pos)) != std::string::npos) {
        s.erase(pos, 1);
    }

    // Trim whitespace (if any)
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());

    if (s.empty()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
