#include <iostream>
#include <string>

// Declare variables
std::string c; // A string to store the input
std::string ans; // A string to store the output

int main() {
    // Initialize variables
    std::cin >> c; // Read a string from the standard input and store it in 'c'

    // Process the string
    for (char ch : c) { // Iterate through each character in the string 'c'
        if (ch != 'B') { // If the current character is not 'B'
            ans += ch; // Append the character to the output string 'ans'
        } else { // If the current character is 'B'
            if (!ans.empty()) { // Check if 'ans' is not empty
                ans.pop_back(); // Remove the last character from the output string 'ans'
            }
        }
    }

    // Print the output
    std::cout << ans << std::endl; // Print the final output string
}

// The comments explain the purpose of each logical block and make the code more readable.
