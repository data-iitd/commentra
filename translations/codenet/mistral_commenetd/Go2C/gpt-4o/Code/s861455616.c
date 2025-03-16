#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation

int main() {
    // Declare a variable named "s" of type char array (string)
    char s[100]; // Assuming a maximum length of 99 characters + null terminator

    // Use the "scanf" function to read a string input from the standard input
    scanf("%s", s);

    // Check if the length of the string "s" is greater than or equal to 4
    // and if its first four characters are "YAKI"
    if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
        // If the condition is true, print the word "Yes" to the standard output
        printf("Yes\n");
    } else {
        // If the condition is false, print the word "No" to the standard output
        printf("No\n");
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
