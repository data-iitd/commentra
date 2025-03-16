#include <stdio.h> // Include standard input-output library
#include <stdbool.h> // Include library for boolean type

int main() {
    char n[100]; // Declare a character array to hold the input string
    scanf("%s", n); // Read the input string
    bool s = false; // Initialize a boolean variable to keep track of the state

    // Process each character in the character array
    for (int i = 0; n[i] != '\0'; i++) {
        if (n[i] == '.') { // Check if the current character is a dot
            if (s) { // If the state is true
                printf("1"); // Print '1' and reset the state to false
                s = false;
            } else { // If the state is false
                printf("0"); // Print '0' and set the state to false
                s = false;
            }
        } else { // If the current character is not a dot
            if (s) { // If the state is true
                printf("2"); // Print '2' and reset the state to false
                s = false;
            } else { // If the state is false
                s = true; // Set the state to true
            }
        }
    }
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
