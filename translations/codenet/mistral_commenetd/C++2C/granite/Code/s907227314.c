
#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Declare a character array variable named s to store the user input
    fgets(s, 100, stdin); // Read a string input from the standard input stream (stdin) and store it in the s variable

    int a = -1, z = -1; // Initialize two integer variables named a and z to -1

    for(int i = 0; i < strlen(s); i++) { // This for loop iterates through each character in the string s
        if (s[i] == 'A') { // Check if the current character is 'A'
            a = i; // If it is, assign the index of the character to the variable a
            break; // Exit the loop once 'A' is found
        }
    }

    for(int i = strlen(s) - 1; i >= 0; i--) { // This for loop iterates through the string in reverse order
        if (s[i] == 'Z') { // Check if the current character is 'Z'
            z = i; // If it is, assign the index of the character to the variable z
            break; // Exit the loop once 'Z' is found
        }
    }

    printf("%d\n", z - a + 1); // Output the difference between the indices of 'Z' and 'A' plus one

    return 0; // Indicate that the program has run successfully
}
