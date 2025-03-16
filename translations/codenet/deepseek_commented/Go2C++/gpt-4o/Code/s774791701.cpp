#include <iostream>
#include <string>

int main() {
    // Declare a string variable to store user input
    std::string s;
    // Read input from the user and store it in the variable `s`
    std::cin >> s;

    // Initialize the price variable with a starting value of 700
    int price = 700;
    // Loop through each character in the string `s`
    for (char c : s) {
        // Check if the current character is 'o'
        if (c == 'o') {
            // If the character is 'o', add 100 to the price
            price += 100;
        }
    }
    // Print the final value of the price
    std::cout << price << std::endl;

    return 0;
}

// <END-OF-CODE>
