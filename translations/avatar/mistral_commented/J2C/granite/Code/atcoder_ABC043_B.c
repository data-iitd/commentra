

#include <stdio.h> // Standard input/output library
#include <string.h> // String manipulation library

int main() {
    char s[100001]; // Input string
    char d[100001]; // Output string
    int i, j; // Loop variables

    fgets(s, 100001, stdin); // Read the input string from the console
    j = 0; // Initialize the output string index

    for (i = 0; s[i]!= '\0'; i++) { // Iterate through each character in the input string
        switch (s[i]) { // Switch statement to handle different characters
            case '0':
                d[j++] = '0'; // Append "0" to the output string
                break;
            case '1':
                d[j++] = '1'; // Append "1" to the output string
                break;
            case 'B':
                if (j > 0) { // If there is a character in the output string
                    j--; // Decrement the output string index
                }
                break;
        }
    }

    d[j] = '\0'; // Null-terminate the output string
    printf("%s\n", d); // Print the output string to the console

    return 0; // Return 0 to indicate successful execution
}

