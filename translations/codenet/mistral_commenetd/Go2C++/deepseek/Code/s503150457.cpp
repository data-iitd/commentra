#include <iostream>
#include <string>
#include <cctype> // for toupper

int main() {
    // Declare strings s1, s2, and s3 for user input
    std::string s1, s2, s3;

    // Read user input for strings s1, s2, and s3
    std::cin >> s1 >> s2 >> s3;

    // Convert the first character of each string to uppercase and concatenate them
    std::string result = "";
    result += std::toupper(s1[0]);
    result += std::toupper(s2[0]);
    result += std::toupper(s3[0]);

    // Print the concatenated uppercase first character of each string
    std::cout << result << std::endl;

    return 0;
}
