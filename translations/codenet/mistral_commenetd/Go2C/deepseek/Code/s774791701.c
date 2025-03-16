#include <stdio.h>

int main() {
    char s[100]; // Declare a character array to store the input string
    int price = 700; // Declare and initialize the 'price' variable with 700

    // Read a string input from the user using scanf() function
    scanf("%s", s);

    // Iterate through each character 'c' in the string 's' using a for loop
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i]; // Get the current character 'c' from the string 's'
        // Check if the current character 'c' is equal to 'o'
        if (c == 'o') {
            // If yes, add 100 to the 'price' variable
            price += 100;
        }
    }

    // Print the final value of 'price' using printf() function
    printf("%d\n", price);

    return 0;
}
