#include <iostream>
#include <cstring>

int main() {
    int sum = 0;
    char x[1002]; // Declare a character array to store the input string

    while (true) {
        std::cin >> x; // Read the first string from the input
        if (x[0] == '0') { // Check if the first character is '0'
            break; // Exit the loop if it is
        }

        sum = 0; // Reset the sum for the new string
        for (int i = 0; i < strlen(x); i++) { // Loop through each character in the string
            sum += x[i] - '0'; // Convert the character to its corresponding digit and add it to the sum
        }
        std::cout << sum << std::endl; // Print the sum of the digits
    }

    return 0;
}

// <END-OF-CODE>
