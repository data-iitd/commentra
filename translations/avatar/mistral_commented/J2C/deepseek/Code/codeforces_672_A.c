#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function named 'generateString' that returns a character array
// representing a string of numbers from 1 to 1000
char* generateString() {
    // Allocate memory for the string (1000 characters + 1 for the null terminator)
    char* str = (char*)malloc(1001 * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Use a for loop to append numbers from 1 to 1000 to the string
    for (int i = 1; i <= 1000; i++) {
        char num[5]; // Buffer to hold the string representation of the number
        sprintf(num, "%d", i); // Convert the number to a string
        strcat(str, num); // Append the string representation to the main string
    }

    return str;
}

// Define the main function that reads user input and prints the result
int main() {
    int n;

    // Read an integer value from the user input
    scanf("%d", &n);

    // Generate the string
    char* str = generateString();

    // Print the character at the specified index of the generated string
    printf("%c\n", str[n - 1]);

    // Free the allocated memory
    free(str);

    return 0;
}
