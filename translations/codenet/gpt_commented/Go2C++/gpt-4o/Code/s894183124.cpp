#include <iostream>
#include <string>

int main() {
    // Declare variables to hold the integer input and the string input
    int n;
    std::string s;
    
    // Read an integer from standard input
    std::cin >> n;
    
    // Read a string from standard input
    std::cin >> s;
    
    // Count the occurrences of the substring "ABC" in the input string
    int count = 0;
    std::string substring = "ABC";
    size_t pos = s.find(substring);
    
    while (pos != std::string::npos) {
        count++;
        pos = s.find(substring, pos + 1);
    }
    
    // Print the result
    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
