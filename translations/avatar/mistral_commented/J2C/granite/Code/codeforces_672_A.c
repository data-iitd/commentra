
#include <stdio.h>
#include <string.h>

// Define a function named 'generateString' that returns a character array
// representing a string of numbers from 1 to 1000
char* generateString() {
    char* str = (char*)malloc(1001 * sizeof(char)); // Allocate memory for the string
    int i;

    // Use a for loop to generate the string of numbers from 1 to 1000
    for (i = 0; i < 1000; i++) {
        str[i] = '0' + (i + 1) % 10; // Convert the current number to a character and append it to the string
    }
    str[1000] = '\0'; // Null-terminate the string

    // Return the generated string
    return str;
}

// Define the main function that reads user input and prints the result
int main() {
    int n;

    // Read an integer value from the user input
    scanf("%d", &n);

    // Print the character at the specified index of the generated string
    printf("%c\n", generateString()[n - 1]);

    return 0;
}
