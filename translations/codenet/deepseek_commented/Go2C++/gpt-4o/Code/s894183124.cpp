#include <iostream>
#include <string>

// Declare necessary headers for input/output and string manipulation.
int main() {
    int n;
    std::string s;
    
    // Declare variables to store the input values.
    // `n` will store the integer input and `s` will store the string input.
    std::cin >> n;
    std::cin >> s;
    
    // Read an integer `n` and a string `s` from the standard input.
    // The `std::cin` is used to read input values.
    
    // Count the number of occurrences of the substring "ABC" in the string `s`.
    // The `std::string::find` method is used to count occurrences of the substring "ABC".
    int count = 0;
    std::string substring = "ABC";
    size_t pos = s.find(substring);
    
    while (pos != std::string::npos) {
        count++;
        pos = s.find(substring, pos + 1);
    }
    
    // Print the number of occurrences.
    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
