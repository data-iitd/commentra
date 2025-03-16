#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    // Allocate enough memory for the string (1 to 1000 concatenated)
    // The maximum length can be calculated as follows:
    // 1-9: 9 characters, 10-99: 180 characters, 100-999: 2700 characters, 1000: 4 characters
    char *str = (char *)malloc(4000 * sizeof(char)); 
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize the string
    str[0] = '\0'; // Start with an empty string

    // Looping through numbers 1 to 1000 and appending them to the string
    for (int i = 1; i <= 1000; i++) {
        char buffer[10]; // Buffer to hold the string representation of the number
        sprintf(buffer, "%d", i); // Convert the number to a string
        strcat(str, buffer); // Append the number string to the main string
    }
    
    return str; // Return the generated string
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n); // Reading an integer input from the user

    char *generatedString = generateString(); // Generate the concatenated string

    // Printing the character at the (n-1)th index of the generated string
    printf("%c\n", generatedString[n - 1]);

    free(generatedString); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
