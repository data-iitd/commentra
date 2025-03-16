#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Initialize an empty string variable 's'
    std::string s;

    // Read a string input from the user
    std::getline(std::cin, s);

    // Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively
    size_t pos;
    while ((pos = s.find("dream")) != std::string::npos) {
        s.replace(pos, 5, "D");
    }
    while ((pos = s.find("erase")) != std::string::npos) {
        s.replace(pos, 5, "E");
    }

    // Remove the substrings "Der" and "Er" from the string 's'
    while ((pos = s.find("Der")) != std::string::npos) {
        s.erase(pos, 3);
    }
    while ((pos = s.find("Er")) != std::string::npos) {
        s.erase(pos, 2);
    }

    // Remove leading and trailing spaces from the string 's'
    s.erase(0, s.find_first_not_of(" \n\r\t")); // trim left
    s.erase(s.find_last_not_of(" \n\r\t") + 1); // trim right

    // Check if the string 's' is empty or not
    if (s.empty()) {
        // Print "YES" if the string 's' is empty
        std::cout << "YES" << std::endl;
    } else {
        // Print "NO" if the string 's' is not empty
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
