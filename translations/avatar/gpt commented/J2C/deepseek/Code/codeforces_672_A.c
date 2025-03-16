#include <stdio.h>
#include <stdlib.h>

// Function to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    // Calculating the size of the final string
    int size = 0;
    for (int i = 1; i <= 1000; i++) {
        size += snprintf(NULL, 0, "%d", i); // Calculating the length of each number
    }

    // Allocating memory for the final string
    char* result = (char*)malloc(size + 1); // +1 for the null terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Building the final string by concatenating numbers 1 to 1000
    char buffer[12]; // Buffer to hold the string representation of each number
    int index = 0;
    for (int i = 1; i <= 1000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i); // Converting the number to a string
        for (int j = 0; buffer[j] != '\0'; j++) {
            result[index++] = buffer[j]; // Copying each character to the result array
        }
    }
    result[index] = '\0'; // Null-terminating the final string

    return result;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Generating the character array
    char* str = generateString();

    // Printing the character at the (n-1)th index of the generated character array
    printf("%c\n", str[n - 1]);

    // Freeing the allocated memory
    free(str);

    return 0;
}
