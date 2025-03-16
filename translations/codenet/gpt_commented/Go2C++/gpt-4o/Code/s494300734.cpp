#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string s;
    
    // Read a string input from the user
    std::cin >> s;
    
    // Initialize the answer variable with "No"
    std::string ans = "No";
    
    // Check if the first occurrence of 'C' is before the last occurrence of 'F'
    size_t indexC = s.find('C');
    size_t indexF = s.rfind('F');
    
    if (indexC != std::string::npos && indexC < indexF) {
        // If true, set the answer to "Yes"
        ans = "Yes";
    }
    
    // Check if 'C' does not exist in the string
    if (indexC == std::string::npos) {
        // If true, set the answer to "No"
        ans = "No";
    }
    
    // Print the final answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
