#include <stdio.h>

int main() {
    // Declare a string variable to store user input
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    // Read input from the user and store it in the variable `s`
    scanf("%s", s);

    // Initialize the price variable with a starting value of 700
    int price = 700;
    // Loop through each character in the string `s`
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the current character is 'o'
        if (s[i] == 'o') {
            // If the character is 'o', add 100 to the price
            price += 100;
        }
    }
    // Print the final value of the price
    printf("%d\n", price);

    return 0;
}

// <END-OF-CODE>
