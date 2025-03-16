#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_INPUT_LENGTH 10000

int main() {
    // Taking the number of sentences n as input
    int n;
    scanf("%d\n", &n);

    // Initializing the answer counter ans and the sum of lengths of sentences sumL
    int ans = 1, sumL = 0;
    char input[MAX_INPUT_LENGTH];

    // Reading the input string
    fgets(input, sizeof(input), stdin);

    // Splitting the input string into sentences based on punctuation marks
    char *token = strtok(input, ".?!");

    while (token != NULL) {
        // Stripping leading and trailing whitespaces from the sentence
        while (isspace((unsigned char)*token)) token++; // Trim leading spaces
        char *end = token + strlen(token) - 1;
        while (end > token && isspace((unsigned char)*end)) end--; // Trim trailing spaces
        end[1] = '\0'; // Null-terminate the trimmed string

        // Adding a dot at the end of the sentence
        char sentence[MAX_SENTENCE_LENGTH];
        snprintf(sentence, sizeof(sentence), "%s.", token);

        // Calculating the length L of the sentence
        int L = strlen(sentence);

        // Checking if the length of the sentence is greater than the number of sentences n
        if (L > n) {
            // Printing an error message and exiting the program if the condition is true
            printf("Impossible\n");
            return 0;
        }

        // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
        if (sumL + L + (sumL > 0)) {
            // Incrementing the answer counter ans if the condition is true
            ans++;
            // Updating the sum of lengths sumL with the length of the current sentence
            sumL = L;
        } else {
            // Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
            sumL = sumL + L + (sumL > 0);
        }

        // Get the next token
        token = strtok(NULL, ".?!");
    }

    // Printing the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
