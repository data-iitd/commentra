
#include <stdio.h>

int main() {
    // Initialize an empty string variable named's'
    char s[100];

    // Read a string input from the user using scanf() function
    scanf("%s", s);

    // Declare a variable named 'price' with initial value 700
    int price = 700;

    // Iterate through each character 'c' in the string's' using a for loop
    for (int i = 0; s[i]!= '\0'; i++) {
        // Check if the current character 'c' is equal to 'o'
        if (s[i] == 'o') {
            // If yes, add 100 to the 'price' variable
            price += 100;
        }
    }

    // Print the final value of 'price' using printf() function
    printf("%d\n", price);

    return 0;
}
