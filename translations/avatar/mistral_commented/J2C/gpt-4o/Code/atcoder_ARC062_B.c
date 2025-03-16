#include <stdio.h>      // For standard input and output
#include <string.h>    // For string manipulation

// Function to solve the problem
void solve(int testNumber, char *S) {
    int score = 0; // Variable to store the score
    int length = strlen(S); // Get the length of the input string

    // Iterate through each character in the string
    for (int i = 0; i < length; i++) {
        char my; // Character representing my move
        char his; // Character representing his move

        // Determine my move based on the index
        my = (i % 2 == 0) ? 'g' : 'p';

        // Read his move from the input string
        his = S[i];

        // Update the score based on the moves
        if (my != his) {
            score += (my == 'p') ? 1 : -1;
        }
    }

    // Print the score
    printf("%d\n", score);
}

// Main function to start the program
int main() {
    char S[100001]; // Array to store the input string

    // Read the input string
    scanf("%s", S);

    // Solve the problem
    solve(1, S); // Call the solve function with test number and input string

    return 0; // Return success
}

// <END-OF-CODE>
