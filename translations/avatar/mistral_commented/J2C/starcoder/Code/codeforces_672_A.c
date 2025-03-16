#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a static method named 'generateString' that returns a character array
// representing a string of numbers from 1 to 1000
char* generateString() {
    char* str = (char*)malloc(sizeof(char) * 1000); // Allocate memory for the string

    // Use a for loop to append numbers from 1 to 1000 to the string
    for (int i = 0; i < 1000; i++) {
        str[i] = (char)(i + 1); // Append the current number to the string
    }

    // Return the string
    return str;
}

// Define the main method that reads user input and prints the result
int main(int argc, char** argv) {
    int n; // Declare an integer variable to store the user input

    scanf("%d", &n); // Read an integer value from the user input

    // Print the character at the specified index of the generated string
    printf("%c", generateString()[n - 1]);

    return 0;
}

