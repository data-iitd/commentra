#include <stdio.h>  // Including standard input/output library
#include <string.h> // Including string library for string manipulation

int main() {
    // Buffer to hold the input string
    char a[1000]; // Assuming the input will not exceed 999 characters
    // Reading a line of input from the user
    fgets(a, sizeof(a), stdin);
    
    // Creating a buffer for the output
    char output[1000];
    int j = 0; // Index for output buffer

    // Replacing commas with spaces
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == ',') {
            output[j++] = ' '; // Replace comma with space
        } else {
            output[j++] = a[i]; // Copy the character as is
        }
    }
    output[j] = '\0'; // Null-terminate the output string

    // Printing the modified string to the console
    printf("%s", output);

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
