#include <stdio.h> // Include the standard I/O library
#include <string.h> // Include the string manipulation library

// Define a variable `s` of type `char` array to store the user input.
char s[100]; // Assuming a maximum length of 100 characters for the input

// Read a string input from the standard input and store it in the variable `s`.
int main() {
    printf("Enter a string: "); // Print a prompt message to the standard output.
    scanf("%99s", s); // Read a string input from the standard input and store it in the variable `s`.

    // Replace all occurrences of the string "2017" in the string `s` with the string "2018".
    char *pos;
    while ((pos = strstr(s, "2017")) != NULL) { // Find the first occurrence of "2017"
        // Replace it with "2018"
        strncpy(pos, "2018", 4); // Copy "2018" to the position of "2017"
        // Move the rest of the string to the right
        memmove(pos + 4, pos + 4, strlen(pos + 4) + 1); // Shift the rest of the string
    }

    // Print the modified string to the standard output.
    printf("Modified string: %s\n", s);
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
