#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    std::string result;
    result += std::toupper(s1[0]);
    result += std::toupper(s2[0]);
    result += std::toupper(s3[0]);

    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
