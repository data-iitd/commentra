

#include <stdio.h> // Standard input/output library
#include <string.h> // String manipulation library

int main() {
    char S[100001]; // String to store the input
    int score = 0; // Variable to store the score

    // Read the input string
    scanf("%s", S);

    // Iterate through each character in the string
    for (int i = 0; i < strlen(S); i++) {
        char my; // Character representing my move
        char his; // Character representing his move

        // Determine my move based on the index
        my = i % 2 == 0? 'g' : 'p';

        // Read his move from the input string
        his = S[i];

        // Update the score based on the moves
        if (my!= his) {
            score += my == 'p'? 1 : -1;
        }
    }

    // Print the score
    printf("%d\n", score);

    return 0; // Return 0 to indicate successful execution
}

These comments should provide a good understanding of what each part of the code does. Let me know if you need any further clarification!