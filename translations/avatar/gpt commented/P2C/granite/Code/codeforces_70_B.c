
#include <stdio.h>  // Include the standard input/output library
#include <regex.h>  // Include the regular expression library

int main() {
    regex_t regex;  // Declare a regular expression object
    int n, ans, sumL, L;  // Declare variables for the maximum allowed length, answer counter, sum of lengths, and sentence length

    // Read an integer input which represents the maximum allowed length for sentences
    scanf("%d", &n);

    // Initialize the answer counter and the sum of lengths of sentences
    ans = 1;
    sumL = 0;

    // Compile the regular expression pattern for splitting the input text into sentences
    regcomp(&regex, "[.?!]", 0);

    // Read the input text and split it into sentences based on the compiled regular expression pattern
    char input[1000];  // Declare a character array to store the input text
    gets(input);  // Read the input text
    regmatch_t matches[1];  // Declare an array to store the matches of the regular expression pattern
    char *start = input;  // Initialize the start pointer to the beginning of the input text
    while (regexec(&regex, start, 1, matches, 0) == 0) {
        char *end = start + matches[0].rm_so;  // Calculate the end pointer of the current sentence
        char sentence[100];  // Declare a character array to store the current sentence
        strncpy(sentence, start, end - start);  // Copy the current sentence from the input text
        sentence[end - start] = '\0';  // Null-terminate the current sentence
        L = strlen(sentence);  // Calculate the length of the current sentence

        // Check if the length of the sentence exceeds the maximum allowed length
        if (L > n) {
            printf("Impossible\n");  // Print "Impossible" and exit
            return 0;
        }

        // Check if adding the current sentence length to the sum exceeds the maximum allowed length
        if (sumL + L + (sumL > 0) > n) {
            ans++;  // Increment the answer counter for a new line
            sumL = L;  // Reset the sum of lengths to the current sentence length
        } else {
            // Update the sum of lengths by adding the current sentence length
            sumL = sumL + L + (sumL > 0);  // Add 1 if there was a previous sentence (to account for space)
        }

        // Update the start pointer to the next sentence
        start = end + matches[0].rm_eo;
    }

    // Print the total number of lines needed
    printf("%d\n", ans);

    // Free the compiled regular expression pattern
    regfree(&regex);

    return 0;  // End of the program
}
