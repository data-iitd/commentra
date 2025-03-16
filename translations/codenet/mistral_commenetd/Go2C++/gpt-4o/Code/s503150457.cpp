#include <iostream>
#include <string>
#include <cctype>

int main() {
    // Declare empty strings s1, s2, and s3 for user input
    std::string s1, s2, s3;

    // Read user input for strings s1, s2, and s3
    std::cin >> s1 >> s2 >> s3;

    // Print the concatenated uppercase first character of each string
    std::cout << static_cast<char>(std::toupper(s1[0])) 
              << static_cast<char>(std::toupper(s2[0])) 
              << static_cast<char>(std::toupper(s3[0])) 
              << std::endl;

    return 0;
}

// <END-OF-CODE>
