#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::getline(std::cin, s); // Step 1: Reading Input

    // Step 2: Replacing Substrings
    size_t pos;
    while ((pos = s.find("dream")) != std::string::npos) {
        s.replace(pos, 5, "D");
    }
    while ((pos = s.find("erase")) != std::string::npos) {
        s.replace(pos, 5, "E");
    }

    // Step 3: Removing Modified Substrings
    while ((pos = s.find("Der")) != std::string::npos) {
        s.erase(pos, 3);
    }
    while ((pos = s.find("Er")) != std::string::npos) {
        s.erase(pos, 2);
    }
    while ((pos = s.find("D")) != std::string::npos) {
        s.erase(pos, 1);
    }
    while ((pos = s.find("E")) != std::string::npos) {
        s.erase(pos, 1);
    }

    // Step 4: Trimming Spaces
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());

    // Step 5: Checking for Emptiness
    if (s.empty()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
