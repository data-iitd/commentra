#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to split the input string into sentences based on punctuation marks
char **split(char *s, int *n) {
    // Initializing the answer counter ans and the sum of lengths of sentences sumL
    int ans = 1, sumL = 0;

    // Loop to split the input string into sentences based on punctuation marks
    for (int i = 0; i < strlen(s); i++) {
        // Checking if the current character is a punctuation mark
        if (ispunct(s[i])) {
            // Stripping leading and trailing whitespaces from the sentence s
            s[i] = '\0';
            s += i + 1;
            i = -1;
        }
    }

    // Loop to calculate the length L of each sentence
    for (int i = 0; i < strlen(s); i++) {
        // Checking if the current character is a punctuation mark
        if (ispunct(s[i])) {
            // Adding a dot at the end of the sentence if it doesn't already have one
            s[i] = '.';
            s += i + 1;
            i = -1;
        }
    }

    // Loop to calculate the sum of lengths of all sentences
    for (int i = 0; i < strlen(s); i++) {
        // Checking if the current character is a punctuation mark
        if (ispunct(s[i])) {
            // Calculating the length L of the sentence s
            int L = i;

            // Checking if the length of the sentence is greater than the number of sentences n
            if (L > *n) {
                // Printing an error message and exiting the program if the condition is true
                printf("Impossible\n");
                exit(0);
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
        }
    }

    // Printing the final answer
    printf("%d\n", ans);

    // Returning the final answer
    return ans;
}

// Main function
int main() {
    // Taking the number of sentences n as input
    int n;
    scanf("%d", &n);

    // Taking the input string as input
    char s[100000];
    scanf("%s", s);

    // Calling the split function to split the input string into sentences based on punctuation marks
    split(s, &n);

    // Ending the program with comment "