
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000000

// Structure to store the input
typedef struct {
    char *input;
    int length;
} Input;

// Function to read the input
Input readInput() {
    char *input = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
    int length = 0;

    // Read the input string
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character
    input[strlen(input) - 1] = '\0';

    // Return the input
    return (Input){input, strlen(input)};
}

// Function to solve the problem
int solve(Input input) {
    int score = 0; // Variable to store the score

    // Iterate through each character in the string
    for (int i = 0; i < input.length; i++) {
        char my; // Character representing my move
        char his; // Character representing his move

        // Determine my move based on the index
        my = i % 2 == 0 ? 'g' : 'p';

        // Read his move from the input string
        his = input.input[i];

        // Update the score based on the moves
        if (my != his) {
            score += my == 'p' ? 1 : -1;
        }
    }

    // Return the score
    return score;
}

// Main function to start the program
int main() {
    Input input = readInput(); // Read the input
    int score = solve(input); // Solve the problem
    printf("%d\n", score); // Print the score
    return 0;
}

