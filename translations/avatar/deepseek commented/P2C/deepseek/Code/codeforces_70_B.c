#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, ans = 1, sumL = 0;
    char *input = malloc(1000001 * sizeof(char));
    char *token, *saveptr;

    // Take the maximum sentence length as input
    scanf("%d", &n);

    // Read the entire input as a single string
    getchar(); // Consume the newline character after the integer input
    fgets(input, 1000001, stdin);

    // Tokenize the input string by splitting it into sentences using the regular expression [.?!]
    token = strtok_r(input, "!?.", &saveptr);
    while (token != NULL) {
        // Strip leading and trailing whitespace and add a period to the end of the sentence
        char *s = strdup(token);
        s = strtok(s, " \t\n\r");
        s = strdup(s);
        s = strtok(s, " \t\n\r");
        s = strcat(s, ".");

        // Calculate the length of the sentence
        int L = strlen(s);

        // Check if the sentence length is greater than 1
        if (L > 1) {
            // Check if the sentence length is greater than the maximum allowed length
            if (L > n) {
                // If the sentence is too long, print "Impossible" and exit
                printf("Impossible\n");
                free(input);
                free(s);
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
                sumL = sumL + L + (sumL > 0);
            }
        }

        // Free the allocated memory for the sentence
        free(s);

        // Get the next sentence
        token = strtok_r(NULL, "!?.", &saveptr);
    }

    // Print the total number of sentences
    printf("%d\n", ans);

    // Free the allocated memory for the input string
    free(input);

    return 0;
}
