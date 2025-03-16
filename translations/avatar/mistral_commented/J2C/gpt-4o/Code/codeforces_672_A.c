#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function named 'generateString' that returns a character array
// representing a string of numbers from 1 to 1000
char* generateString() {
    // Allocate enough memory for the string (1 to 1000 has 2889 characters)
    char* str = (char*)malloc(2889 * sizeof(char));
    if (str == NULL) {
        return NULL; // Check for memory allocation failure
    }

    // Use a variable to keep track of the current position in the string
    int pos = 0;

    // Use a for loop to append numbers from 1 to 1000 to the string
    for (int i = 1; i <= 1000; i++) {
        // Convert the integer to a string and copy it to the character array
        pos += sprintf(str + pos, "%d", i);
    }

    return str; // Return the generated string
}

// Define the main function that reads user input and prints the result
int main() {
    int n;
    printf("Enter an index (1-2889): ");
    scanf("%d", &n); // Read an integer value from the user input

    // Generate the string of numbers
    char* generatedString = generateString();
    if (generatedString == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    // Print the character at the specified index of the generated string
    if (n > 0 && n <= strlen(generatedString)) {
        printf("%c\n", generatedString[n - 1]);
    } else {
        printf("Index out of bounds.\n");
    }

    // Free the allocated memory
    free(generatedString);
    return 0;
}

// <END-OF-CODE>
