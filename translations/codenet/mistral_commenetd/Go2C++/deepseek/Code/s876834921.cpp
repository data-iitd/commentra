#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    // Read a string input from the user using 'std::cin'
    std::cin >> s;

    // Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using 'std::string::replace' function
    std::string::size_type pos = 0;
    while ((pos = s.find("dream", pos)) != std::string::npos) {
        s.replace(pos, 5, "D");
        pos += 1;
    }

    pos = 0;
    while ((pos = s.find("erase", pos)) != std::string::npos) {
        s.replace(pos, 5, "E");
        pos += 1;
    }

    // Remove the substrings "Der" and "Er" from the string 's' using 'std::string::erase' function
    pos = 0;
    while ((pos = s.find("Der", pos)) != std::string::npos) {
        s.erase(pos, 3);
    }

    pos = 0;
    while ((pos = s.find("Er", pos)) != std::string::npos) {
        s.erase(pos, 2);
    }

    // Remove leading and trailing spaces from the string 's' using 'std::string::erase' function
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

    // Check if the string 's' is empty or not
    if (s.empty()) {
        // Print "YES" if the string 's' is empty
        std::cout << "YES" << std::endl;
    } else {
        // Print "NO" if the string 's' is not empty
        std::cout << "NO" << std::endl;
    }

    // End of the code
    return 0;
}

