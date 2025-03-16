
#include <iostream>
#include <string>

int main() {
    // Declare a string variable to hold user input
    std::string s;
    
    // Read input from the user
    std::cin >> s;
    
    // Replace occurrences of "dream" with "D"
    size_t pos = s.find("dream");
    while (pos!= std::string::npos) {
        s.replace(pos, 5, "D");
        pos = s.find("dream", pos + 1);
    }
    
    // Replace occurrences of "erase" with "E"
    pos = s.find("erase");
    while (pos!= std::string::npos) {
        s.replace(pos, 5, "E");
        pos = s.find("erase", pos + 1);
    }
    
    // Remove occurrences of "Der" from the string
    pos = s.find("Der");
    while (pos!= std::string::npos) {
        s.erase(pos, 3);
        pos = s.find("Der", pos + 1);
    }
    
    // Remove occurrences of "Er" from the string
    pos = s.find("Er");
    while (pos!= std::string::npos) {
        s.erase(pos, 2);
        pos = s.find("Er", pos + 1);
    }
    
    // Remove occurrences of "D" from the string
    pos = s.find("D");
    while (pos!= std::string::npos) {
        s.erase(pos, 1);
        pos = s.find("D", pos + 1);
    }
    
    // Remove occurrences of "E" from the string
    pos = s.find("E");
    while (pos!= std::string::npos) {
        s.erase(pos, 1);
        pos = s.find("E", pos + 1);
    }
    
    // Trim any leading or trailing whitespace from the string
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return!std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return!std::isspace(ch);
    }).base(), s.end());

    // Check if the resulting string is empty
    if (s.empty()) {
        // If the string is empty, print "YES"
        std::cout << "YES" << std::endl;
    } else {
        // If the string is not empty, print "NO"
        std::cout << "NO" << std::endl;
    }
    
    // END-OF-CODE
}