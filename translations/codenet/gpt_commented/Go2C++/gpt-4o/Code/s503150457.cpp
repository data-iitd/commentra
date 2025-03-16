#include <iostream>
#include <string>
#include <cctype>

int main() {
    // Declare three string variables to hold user input
    std::string s1, s2, s3;
    
    // Read three strings from standard input
    std::cin >> s1 >> s2 >> s3;

    // Convert the first character of each string to uppercase and concatenate them
    std::string result;
    result += std::toupper(s1[0]);
    result += std::toupper(s2[0]);
    result += std::toupper(s3[0]);
    
    // Print the concatenated result
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
