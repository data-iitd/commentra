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
    // and print the result
    int count = 0;
    size_t pos = s.find("ABC");
    while (pos != std::string::npos) {
        count++;
        pos = s.find("ABC", pos + 3);
    }
    std::cout << count << std::endl;
    
    return 0;
}

