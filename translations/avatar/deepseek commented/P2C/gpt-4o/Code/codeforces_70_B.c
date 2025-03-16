#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    // Take the maximum sentence length as input
    int n;
    scanf("%d\n", &n);

    // Initialize variables to keep track of the number of sentences and their cumulative length
    int ans = 1, sumL = 0;
    char inputString[MAX_LENGTH];

    // Take a string input
    fgets(inputString, sizeof(inputString), stdin);

    // Tokenize the input string using the delimiters . ? !
    char *token = strtok(inputString, ".?!");

    while (token != NULL) {
        // Strip leading and trailing whitespace
        while (isspace((unsigned char)*token)) token++;
        char *end = token + strlen(token) - 1;
        while (end > token && isspace((unsigned char)*end)) end--;
        end[1] = '\0'; // Null-terminate the trimmed string

        // Add a period to the end of the sentence
        char sentence[MAX_LENGTH];
        snprintf(sentence, sizeof(sentence), "%s.", token);
        
        // Calculate the length of the sentence
        int L = strlen(sentence);

        // Check if the sentence length is greater than 1
        if (L > 1) {
            // Check if the sentence length is greater than the maximum allowed length
            if (L > n) {
                // If the sentence is too long, print "Impossible" and exit
                printf("Impossible\n");
                return 0;
            }

            // Check if adding the current sentence would exceed the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                // If adding the sentence would exceed the maximum length, increment the sentence count
                ans++;
                // Reset the cumulative length to the length of the current sentence
                sumL = L;
            } else {
                // Otherwise, add the length of the current sentence to the cumulative length
                sumL += L + (sumL > 0);
            }
        }

        // Get the next token
        token = strtok(NULL, ".?!");
    }

    // Print the total number of sentences
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
