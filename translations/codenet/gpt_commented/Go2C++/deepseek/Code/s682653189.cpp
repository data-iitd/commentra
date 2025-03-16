#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string s;
    
    // Read a string input from the user
    std::cin >> s;
    
    // Loop through each character in the string
    for (size_t i = 0; i < s.length(); i++) {
        // Print 'x' for each character in the input string
        std::cout << 'x';
    }
    
    // Print a newline after printing all 'x's
    std::cout << std::endl;
    
    return 0;
}
