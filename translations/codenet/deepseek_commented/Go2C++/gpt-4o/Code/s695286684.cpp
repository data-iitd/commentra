#include <iostream>
#include <string>

int main() {
    std::string s;
    // Read a string from the standard input and store it in the variable 's'.
    std::cin >> s;
    // Replace all occurrences of "2017" with "2018" in the string 's' and print the result.
    size_t pos = 0;
    while ((pos = s.find("2017", pos)) != std::string::npos) {
        s.replace(pos, 4, "2018");
        pos += 4; // Move past the last replaced substring
    }
    std::cout << s << std::endl;
    return 0;
}

// <END-OF-CODE>
