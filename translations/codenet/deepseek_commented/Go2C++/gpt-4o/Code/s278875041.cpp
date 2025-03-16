#include <iostream>
#include <string>

int main() {
    // Declare a string variable to hold user input
    std::string a;
    
    // Read input from the user and store it in `a`
    std::cin >> a;
    
    // Replace all occurrences of "1" with "0" in the string `a`
    std::string tmp = a;
    for (char &c : tmp) {
        if (c == '1') {
            c = '0';
        }
    }
    
    // Store the result of the first replacement in a temporary variable `tmp`
    // Replace all occurrences of "9" with "1" in the string `tmp`
    std::string b = tmp;
    for (char &c : b) {
        if (c == '9') {
            c = '1';
        }
    }
    
    // Store the result of the second replacement in the variable `b`
    // Replace all occurrences of "0" with "9" in the string `b`
    std::string ans = b;
    for (char &c : ans) {
        if (c == '0') {
            c = '9';
        }
    }
    
    // Print the final result to the console
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
