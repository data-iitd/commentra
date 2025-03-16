#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, ans = 1, sumL = 0;
    char *input = NULL;
    size_t len = 0;

    // Read an integer input which represents the maximum allowed length for sentences
    scanf("%d", &n);

    // Read the entire input text
    getline(&input, &len, stdin);

    // Initialize a buffer to store the current sentence
    char buffer[1000];
    int bufferIndex = 0;

    // Iterate over the input text to split it into sentences
    for (char *token = strtok(input, ".?!"); token != NULL; token = strtok(NULL, ".?!")) {
        // Strip whitespace and add a period to the end of the sentence
        int i;
        for (i = 0; token[i] != '\0'; i++) {
            if (token[i] != ' ' && token[i] != '\n') {
                buffer[bufferIndex++] = token[i];
            }
        }
        buffer[bufferIndex++] = '.';
        buffer[bufferIndex] = '\0';

        // Calculate the length of the current sentence
        int L = bufferIndex;

        // Check if the length of the sentence is greater than 1
        if (L > 1) {
            // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
            if (L > n) {
                printf("Impossible\n");
                free(input);
                return 0;
            }

            // Check if adding the current sentence length to the sum exceeds the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                ans++;  // Increment the answer counter for a new line
                sumL = L;  // Reset the sum of lengths to the current sentence length
            } else {
                // Update the sum of lengths by adding the current sentence length
                sumL = sumL + L + (sumL > 0);  // Add 1 if there was a previous sentence
            }
        }

        // Reset the buffer index for the next sentence
        bufferIndex = 0;
    }

    // Print the total number of lines needed
    printf("%d\n", ans);

    // Free the allocated memory for the input
    free(input);

    return 0;
}
