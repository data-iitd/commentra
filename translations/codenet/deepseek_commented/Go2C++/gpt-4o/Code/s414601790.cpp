#include <iostream>
#include <string>

int main() {
    int n; // Declare an integer variable to store the number of characters in the string
    std::string s; // Declare a string variable to store the input string
    std::cin >> n >> s; // Read input values for n and s from the standard input

    int max = 0; // Initialize max to 0, this will store the maximum value of cnt
    int cnt = 0; // Initialize cnt to 0, this will keep track of the count of 'I' minus 'D'
    
    for (char r : s) { // Loop through each character in the string s
        if (r == 'I') { // If the character is 'I'
            cnt++; // Increment cnt
        } else { // If the character is 'D'
            cnt--; // Decrement cnt
        }

        if (cnt > max) { // Check if the current cnt is greater than max
            max = cnt; // Update max to be equal to cnt
        }
    }

    std::cout << max << std::endl; // Print the maximum value of cnt encountered
    return 0;
}

// <END-OF-CODE>
