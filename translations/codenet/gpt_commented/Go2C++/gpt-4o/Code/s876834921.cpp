#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Declare a string variable to hold user input
    std::string s;
    
    // Read input from the user
    std::getline(std::cin, s);
    
    // Replace occurrences of "dream" with "D"
    size_t pos = 0;
    while ((pos = s.find("dream", pos)) != std::string::npos) {
        s.replace(pos, 5, "D");
        pos += 1; // Move past the replacement
    }
    
    // Replace occurrences of "erase" with "E"
    pos = 0;
    while ((pos = s.find("erase", pos)) != std::string::npos) {
        s.replace(pos, 5, "E");
        pos += 1; // Move past the replacement
    }
    
    // Remove occurrences of "Der" from the string
    pos = 0;
    while ((pos = s.find("Der", pos)) != std::string::npos) {
        s.erase(pos, 3);
    }
    
    // Remove occurrences of "Er" from the string
    pos = 0;
    while ((pos = s.find("Er", pos)) != std::string::npos) {
        s.erase(pos, 2);
    }
    
    // Remove occurrences of "D" from the string
    pos = 0;
    while ((pos = s.find("D", pos)) != std::string::npos) {
        s.erase(pos, 1);
    }
    
    // Remove occurrences of "E" from the string
    pos = 0;
    while ((pos = s.find("E", pos)) != std::string::npos) {
        s.erase(pos, 1);
    }
    
    // Trim any leading or trailing whitespace from the string
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());

    // Check if the resulting string is empty
    if (s.empty()) {
        // If the string is empty, print "YES"
        std::cout << "YES" << std::endl;
    } else {
        // If the string is not empty, print "NO"
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
