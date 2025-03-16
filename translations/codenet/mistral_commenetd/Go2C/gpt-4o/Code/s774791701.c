#include <stdio.h>

int main() {
    // Initialize an empty string variable named 's'
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator

    // Read a string input from the user
    scanf("%s", s);

    // Declare a variable named 'price' with initial value 700
    int price = 700;

    // Iterate through each character 'c' in the string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        // Check if the current character 'c' is equal to 'o'
        if (c == 'o') {
            // If yes, add 100 to the 'price' variable
            price += 100;
        }
    }

    // Print the final value of 'price'
    printf("%d\n", price);

    return 0;
}

// <END-OF-CODE>
