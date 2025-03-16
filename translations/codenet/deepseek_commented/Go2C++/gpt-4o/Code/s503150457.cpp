#include <iostream>
#include <string>
#include <cctype>

int main() {
    // Declare three string variables to hold the input values
    std::string s1, s2, s3;

    // Read input values for s1, s2, and s3 from the standard input
    std::cin >> s1 >> s2 >> s3;

    // Print the uppercase version of the first character of each input string
    std::cout << static_cast<char>(std::toupper(s1[0])) 
              << static_cast<char>(std::toupper(s2[0])) 
              << static_cast<char>(std::toupper(s3[0])) 
              << std::endl;

    return 0;
}

// <END-OF-CODE>
