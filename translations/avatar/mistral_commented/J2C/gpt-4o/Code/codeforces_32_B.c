#include <stdio.h>  // Including standard input-output library
#include <stdbool.h> // Including library for boolean type
#include <string.h> // Including string library for string manipulation

int main() { // Starting the main function
    char n[100]; // Declaring a character array to hold the input string
    scanf("%s", n); // Reading a string from the console

    bool s = false; // Initializing a boolean variable 's' to false

    for (int i = 0; i < strlen(n); i++) { // Starting a for loop to iterate through each character in the string 'n'
        if (n[i] == '.') { // Checking if the current character is a '.'
            if (s) { // If the boolean variable 's' is true
                printf("1"); // Printing '1' to the console
                s = false; // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                printf("0"); // Printing '0' to the console
            }
        } else { // If the current character is not a '.'
            if (s) { // If the boolean variable 's' is true
                printf("2"); // Printing '2' to the console
                s = false; // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                s = true; // Setting the boolean variable 's' to true
            }
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
