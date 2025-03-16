#include <iostream>
#include <string>

int main() {
    // Initialize an empty string variable named 's'
    std::string s;

    // Read a string input from the user
    std::cin >> s;

    // Declare a variable named 'price' with initial value 700
    int price = 700;

    // Iterate through each character 'c' in the string 's'
    for (char c : s) {
        // Check if the current character 'c' is equal to 'o'
        if (c == 'o') {
            // If yes, add 100 to the 'price' variable
            price += 100;
        }
    }

    // Print the final value of 'price'
    std::cout << price << std::endl;

    return 0;
}

// <END-OF-CODE>
