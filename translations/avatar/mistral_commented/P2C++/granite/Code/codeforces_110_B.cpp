

#include <iostream>
#include <string>

int main() {
    // Define a constant string "abcd"
    std::string LUCKY = "abcd";

    // Ask the user to input an integer n
    int n;
    std::cin >> n;

    // Initialize an empty string s
    std::string s = "";

    // Use a for loop to iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Add the character at index i % 4 of the string LUCKY to the string s
        s += LUCKY[i % 4];
    }

    // Print the final string s
    std::cout << s << std::endl;

    return 0;
}

