#include <iostream>
#include <string>

int main() {
    // Initialize a string variable to store the input
    std::string s;
    // Read input from the standard input and store it in the variable `s`
    std::cin >> s;
    
    // Initialize a variable to count the number of '1's in the input string
    int ans = 0;
    // Iterate over each character in the string `s`
    for (char c : s) {
        // Check if the character is '1'
        if (c == '1') {
            // Increment the count of '1's
            ans++;
        }
    }
    // Print the count of '1's to the standard output
    std::cout << ans << std::endl;
}

