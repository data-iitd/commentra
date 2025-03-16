#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string s;
    
    // Read input from the user and store it in the variable 's'
    std::cin >> s;
    
    // Initialize a counter to keep track of the number of '1's in the string
    int ans = 0;
    
    // Iterate over each character in the input string
    for (char c : s) {
        // Check if the current character is '1'
        if (c == '1') {
            // Increment the counter if '1' is found
            ans++;
        }
    }
    
    // Print the total count of '1's found in the input string
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
