#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

int main() {
    // Read an integer input which represents the maximum allowed length for sentences
    int n;
    scanf("%d", &n);

    // Initialize the answer counter and the sum of lengths of sentences
    int ans = 1, sumL = 0;

    // Split the input text into sentences based on punctuation marks (.,?,!)
    char *text = malloc(1000000);
    scanf("%[^\n]%*c", text);
    regex_t regex;
    regcomp(&regex, "[.?!]\\s*", REG_EXTENDED);
    char *token = NULL;
    while (regex_search(text, &token, &regex, 0)) {
        char *s = malloc(strlen(token) + 1);
        strcpy(s, token);
        free(token);
        token = NULL;
        s[strlen(s) - 1] = '.';
        int L = strlen(s);

        // Check if the length of the sentence is greater than 1 (to avoid empty sentences)
        if (L > 1) {
            // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
            if (L > n) {
                printf("Impossible");
                exit(0);
            }

            // Check if adding the current sentence length to the sum exceeds the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                ans += 1;  // Increment the answer counter for a new line
                sumL = L;  // Reset the sum of lengths to the current sentence length
            } else {
                // Update the sum of lengths by adding the current sentence length
                sumL = sumL + L + (sumL > 0);  // Add 1 if there was a previous sentence (to account for space)
        }
        free(s);
        regfree(&regex);
        regcomp(&regex, "[.?!]\\s*", REG_EXTENDED);
    }
    printf("%d", ans);
    return 0;
}

