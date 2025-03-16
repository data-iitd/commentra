#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next token from the input
char* next(FILE* input) {
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, input) == -1) {
        free(line);
        return NULL;
    }

    // Find the first non-space character
    char* token = line;
    while (*token == ' ' || *token == '\t') {
        token++;
    }

    // Find the end of the token
    char* end = token;
    while (*end != ' ' && *end != '\t' && *end != '\0') {
        end++;
    }

    // Null-terminate the token
    if (*end != '\0') {
        *end = '\0';
    }

    return token;
}

// Function to calculate the score based on the input string
void solve(FILE* input, FILE* output) {
    char* S = next(input);
    int score = 0;

    // Iterate through each character in the string S
    for (int i = 0; i < strlen(S); i++) {
        char my = i % 2 == 0 ? 'g' : 'p';
        char his = S[i];

        // Compare the expected character with the actual character and update the score
        if (my != his) {
            score += my == 'p' ? 1 : -1;
        }
    }

    // Print the final score
    fprintf(output, "%d\n", score);

    // Free the allocated memory for the input string
    free(S);
}

int main() {
    // Open the input and output streams
    FILE* input = stdin;
    FILE* output = stdout;

    // Call the solve function
    solve(input, output);

    // Close the streams
    fclose(input);
    fclose(output);

    return 0;
}
