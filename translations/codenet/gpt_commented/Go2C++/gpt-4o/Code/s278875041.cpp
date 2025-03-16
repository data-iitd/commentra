#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string a;
    
    // Read input from the user and store it in variable 'a'
    std::cin >> a;
    
    // Replace all occurrences of '1' with '0' in the input string
    for (char &c : a) {
        if (c == '1') {
            c = '0';
        }
    }
    
    // Replace all occurrences of '9' with '1' in the modified string
    for (char &c : a) {
        if (c == '9') {
            c = '1';
        }
    }
    
    // Replace all occurrences of '0' with '9' in the second modified string
    for (char &c : a) {
        if (c == '0') {
            c = '9';
        }
    }
    
    // Print the final transformed string
    std::cout << a << std::endl;

    return 0;
}

// <END-OF-CODE>
