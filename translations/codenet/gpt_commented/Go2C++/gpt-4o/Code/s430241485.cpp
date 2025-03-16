#include <iostream>
#include <string>

int main() {
    // Declare two string variables to hold input values
    std::string s, t;
    
    // Read two strings from standard input
    std::cin >> s >> t;
    
    // Print the concatenation of the second string followed by the first string
    std::cout << t + s << std::endl;

    return 0;
}

// <END-OF-CODE>
