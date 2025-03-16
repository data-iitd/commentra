#include <stdio.h>      // For standard input and output
#include <stdlib.h>     // For memory allocation and other utilities
#include <string.h>     // For string manipulation

// Function to read a string from input
void readString(char *str, int maxLength) {
    fgets(str, maxLength, stdin); // Read a line from stdin
    str[strcspn(str, "\n")] = 0;   // Remove the newline character if present
}

// The main function
int main() {
    char S[100001]; // Declare a string to hold the input (assuming max length of 100000)
    int score = 0;  // Initialize the score to 0

    readString(S, sizeof(S)); // Read the input string

    // Iterate through each character in the string S
    for (int i = 0; i < strlen(S); i++) {
        char my = (i % 2 == 0) ? 'g' : 'p'; // Determine the expected character based on the index
        char his = S[i]; // Get the character at the current index in S

        // Compare the expected character with the actual character and update the score
        if (my != his) {
            score += (my == 'p') ? 1 : -1; // Update the score based on the expected character
        }
    }

    printf("%d\n", score); // Print the final score
    return 0; // Return success
}

// <END-OF-CODE>
