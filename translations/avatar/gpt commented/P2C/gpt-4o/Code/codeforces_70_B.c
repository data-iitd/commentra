#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d\n", &n);  // Read the maximum allowed length for sentences

    int ans = 1;  // Initialize the answer counter
    int sumL = 0; // Initialize the sum of lengths of sentences
    char input[10000]; // Buffer to hold the input text

    // Read the input text
    fgets(input, sizeof(input), stdin);

    // Tokenize the input text based on punctuation marks (., ?, !)
    char *token = strtok(input, ".!?");
    while (token != NULL) {
        // Strip whitespace and add a period to the end of the sentence
        char *s = token;
        while (isspace(*s)) s++; // Skip leading whitespace
        int L = strlen(s); // Calculate the length of the current sentence
        if (L > 0 && s[L - 1] == '\n') s[--L] = '\0'; // Remove newline if present
        L++; // Account for the period we will add

        // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
        if (L > n) {
            printf("Impossible\n");
            return 0;
        }

        // Check if adding the current sentence length to the sum exceeds the maximum allowed length
        if (sumL + L + (sumL > 0) > n) {
            ans++; // Increment the answer counter for a new line
            sumL = L; // Reset the sum of lengths to the current sentence length
        } else {
            // Update the sum of lengths by adding the current sentence length
            sumL += L + (sumL > 0); // Add 1 if there was a previous sentence (to account for space)
        }

        // Get the next token
        token = strtok(NULL, ".!?");
    }

    // Print the total number of lines needed
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
