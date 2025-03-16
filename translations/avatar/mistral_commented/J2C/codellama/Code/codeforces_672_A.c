// Include the header file for the standard input/output library
#include <stdio.h>

// Include the header file for the string manipulation library
#include <string.h>

// Define a function named 'generateString' that returns a character array
// representing a string of numbers from 1 to 1000
char *generateString() {
    // Declare a character array to store the generated string
    char str[1001];

    // Use a for loop to append numbers from 1 to 1000 to the character array
    for (int i = 1; i <= 1000; i++) {
        // Append the current number to the character array
        strcat(str, itoa(i, str, 10));
    }

    // Return the character array
    return str;
}

// Define the main function that reads user input and prints the result
int main() {
    // Declare an integer variable to store the user input
    int n;

    // Read an integer value from the user input
    scanf("%d", &n);

    // Print the character at the specified index of the generated string
    printf("%c\n", generateString()[n - 1]);

    // Return 0 to indicate successful execution
    return 0;
}

