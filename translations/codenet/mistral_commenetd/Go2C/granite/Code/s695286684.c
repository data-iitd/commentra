
#include <stdio.h> // Include the standard input/output library.
#include <string.h> // Include the string manipulation library.

int main() {
    char s[100]; // Declare a character array `s` to store the user input.
    printf("Enter a string: "); // Print a prompt message to the standard output.
    scanf("%s", s); // Read a string input from the standard input and store it in the character array `s`.

    // Replace all occurrences of the string "2017" in the string `s` with the string "2018".
    char *p = strstr(s, "2017"); // Find the first occurrence of the string "2017" in the string `s`.
    while (p!= NULL) { // Loop until all occurrences of "2017" are replaced.
        strncpy(p, "2018", 5); // Replace the substring "2017" with "2018" in the string `s`.
        p = strstr(p + 1, "2017"); // Find the next occurrence of the string "2017" in the string `s`.
    }

    // Print the modified string to the standard output.
    printf("Modified string: %s\n", s); // Print the modified string to the standard output.

    return 0; // Return 0 to indicate successful execution of the program.
}

// End of code.
