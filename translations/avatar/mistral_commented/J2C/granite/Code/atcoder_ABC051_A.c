

#include <stdio.h> // Include standard input/output library
#include <string.h> // Include string manipulation library

int main() { // Main function to start the program
    char a[1000]; // Declare a character array variable to store the input string
    char b[1000]; // Declare a character array variable to store the modified string

    // Read the input string from the console and store it in the 'a' variable
    scanf("%s", a);

    // Replace all occurrences of ',' in the 'a' string with a single space and store the result in the 'b' variable
    strcpy(b, a); // Copy the contents of 'a' to 'b'
    for (int i = 0; i < strlen(b); i++) { // Iterate over each character in the 'b' string
        if (b[i] == ',') { // Check if the current character is ','
            b[i] =''; // Replace ',' with''
        }
    }

    // Print the modified string stored in the 'b' variable to the console
    printf("%s\n", b); // Print the modified string

    return 0; // Return 0 to indicate successful execution of the program
}

