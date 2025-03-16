#include <stdio.h>  // Include standard input/output library
#include <string.h> // Include string library for string manipulation

int main() {
    char a[1000]; // Declare a character array to store the input string
    char result[1000]; // Declare a character array to store the modified string
    int j = 0; // Index for the result array

    // Read the input string from the console
    fgets(a, sizeof(a), stdin);

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != ',') { // If the character is not a comma
            result[j++] = a[i]; // Add it to the result array
        } else if (j > 0 && result[j - 1] != ' ') { // If it's a comma and the last character in result is not a space
            result[j++] = ' '; // Add a space to the result array
        }
    }
    result[j] = '\0'; // Null-terminate the result string

    // Print the modified string
    printf("%s", result);

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
