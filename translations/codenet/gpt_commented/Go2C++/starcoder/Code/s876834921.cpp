#include <iostream>
#include <string>

int main() {
    // Declare a string variable to hold user input
    std::string s;
    
    // Read input from the user
    std::cin >> s;
    
    // Replace occurrences of "dream" with "D"
    s = std::string(s.replace("dream", "D"));
    
    // Replace occurrences of "erase" with "E"
    s = std::string(s.replace("erase", "E"));
    
    // Remove occurrences of "Der" from the string
    s = std::string(s.replace("Der", ""));
    
    // Remove occurrences of "Er" from the string
    s = std::string(s.replace("Er", ""));
    
    // Remove occurrences of "D" from the string
    s = std::string(s.replace("D", ""));
    
    // Remove occurrences of "E" from the string
    s = std::string(s.replace("E", ""));
    
    // Trim any leading or trailing whitespace from the string
    s = std::string(s.erase(s.begin(), std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base()));

    // Check if the resulting string is empty
    if (s.empty()) {
        // If the string is empty, print "YES"
        std::cout << "YES" << std::endl;
    } else {
        // If the string is not empty, print "NO"
        std::cout << "NO" << std::endl;
    }
}

