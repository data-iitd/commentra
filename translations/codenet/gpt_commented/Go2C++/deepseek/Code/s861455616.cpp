#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string s;
    
    // Read input from the user and store it in the variable 's'
    std::cin >> s;
    
    // Check if the length of the string is at least 4 characters 
    // and if the first four characters are "YAKI"
    if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
        // If the condition is true, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print "No"
        std::cout << "No" << std::endl;
    }
    
    return 0;
}

