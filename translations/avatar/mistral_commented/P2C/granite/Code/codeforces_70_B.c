
#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
    // Taking the number of sentences n as input
    int n;
    scanf("%d", &n);

    // Initializing the answer counter ans and the sum of lengths of sentences sumL
    int ans = 1, sumL = 0;

    // Regular expression pattern for splitting the input string into sentences
    regex_t regex;
    regcomp(&regex, "[.?!]", 0);

    // Input string containing the text
    char input[1000];
    fgets(input, 1000, stdin);

    // Substituting all punctuation marks with a dot followed by a space
    regsub(&regex, input, ". ");

    // Splitting the input string into sentences based on the modified input
    char *token = strtok(input, ". ");

    // Loop to iterate over each sentence in the input string
    while (token!= NULL) {
        // Stripping leading and trailing whitespaces from the sentence token
        char *s = trim(token);

        // Calculating the length L of the sentence s
        int L = strlen(s);

        // Checking if the length of the sentence is greater than the number of sentences n
        if (L > n) {
            // Printing an error message and exiting the program if the condition is true
            printf("Impossible\n");
            return 0;
        }

        // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
        if (sumL + L + (sumL > 0) > n) {
            // Incrementing the answer counter ans if the condition is true
            ans++;
            // Updating the sum of lengths sumL with the length of the current sentence
            sumL = L;
        } else {
            // Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
            sumL = sumL + L + (sumL > 0);
        }

        // Getting the next sentence from the input string
        token = strtok(NULL, ". ");
    }

    // Printing the final answer
    printf("%d\n", ans);

    // Freeing the memory allocated for the regular expression
    regfree(&regex);

    return 0;
}

// Function to trim leading and trailing whitespaces from a string
char *trim(char *str) {
    // Finding the first non-whitespace character from the beginning of the string
    char *start = str;
    while (*start!= '\0' && isspace(*start)) {
        start++;
    }

    // Finding the last non-whitespace character from the end of the string
    char *end = str + strlen(str) - 1;
    while (end >= start && isspace(*end)) {
        end--;
    }

    // Null-terminating the trimmed string
    *(end + 1) = '\0';

    return start;
}

// End of code
