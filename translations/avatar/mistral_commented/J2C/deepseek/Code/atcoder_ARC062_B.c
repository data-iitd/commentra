#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next token from input
char* next() {
    char buffer[100000];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char* token = strtok(buffer, " \n");
        return token;
    }
    return NULL;
}

// Main function to start the program
int main() {
    char S[100000];
    int score = 0;

    // Read the input string
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = 0; // Remove newline character

    // Iterate through each character in the string
    for (int i = 0; i < strlen(S); i++) {
        char my; // Character representing my move
        char his; // Character representing his move

        // Determine my move based on the index
        my = i % 2 == 0 ? 'g' : 'p';

        // Read his move from the input string
        his = S[i];

        // Update the score based on the moves
        if (my != his) {
            score += my == 'p' ? 1 : -1;
        }
    }

    // Print the score
    printf("%d\n", score);

    return 0;
}
