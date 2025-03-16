
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library

int main() {
    char n[1000]; // Declare a character array to store the input string
    fgets(n, sizeof(n), stdin); // Read the input string from the user
    bool s = false; // Declare a boolean variable to keep track of the state
    int len = strlen(n); // Get the length of the input string

    // Process each character in the input string
    for (int i = 0; i < len; i++) {
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
    return 0; // Return 0 to indicate successful execution
}
