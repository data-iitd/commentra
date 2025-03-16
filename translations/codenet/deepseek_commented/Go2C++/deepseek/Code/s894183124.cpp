#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    
    // Read an integer `n` and a string `s` from the standard input.
    std::cin >> n >> s;
    
    // Count the number of occurrences of the substring "ABC" in the string `s`.
    int count = 0;
    size_t pos = s.find("ABC");
    while (pos != std::string::npos) {
        count++;
        pos = s.find("ABC", pos + 3);
    }
    
    // Print the number of occurrences of the substring "ABC" in the string `s`.
    std::cout << count << std::endl;
    
    return 0;
}
