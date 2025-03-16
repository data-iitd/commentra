#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, ans = 1, sumL = 0;
    char *input = NULL;
    size_t len = 0;

    // Taking the number of sentences n as input
    scanf("%d", &n);

    // Reading the entire input into a dynamically allocated string
    getline(&input, &len, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Loop to split the input string into sentences based on punctuation marks
    char *token = strtok(input, ".?! ");
    while (token != NULL) {
        char *s = token;
        // Stripping leading and trailing whitespaces from the sentence s
        while (*s == ' ') s++;
        while (*(s + strlen(s) - 1) == ' ') *(s + strlen(s) - 1) = '\0';

        // Adding a dot at the end of the sentence if it doesn't already have one
        strcat(s, ".");

        // Calculating the length L of the sentence s
        int L = strlen(s);

        // Checking if the length of the sentence is greater than the number of sentences n
        if (L > n) {
            // Printing an error message and exiting the program if the condition is true
            printf("Impossible\n");
            free(input);
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

        // Getting the next sentence
        token = strtok(NULL, ".?! ");
    }

    // Printing the final answer
    printf("%d\n", ans);

    // Freeing the dynamically allocated input string
    free(input);

    return 0;
}
