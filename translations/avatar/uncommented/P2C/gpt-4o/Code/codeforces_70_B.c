#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d\n", &n); // Read the integer input
    int ans = 1, sumL = 0;
    char input[1000]; // Assuming the input string won't exceed 1000 characters
    fgets(input, sizeof(input), stdin); // Read the input string

    char *token = strtok(input, ".?!"); // Split the input based on delimiters
    while (token != NULL) {
        char s[1000]; // Buffer for the sentence
        snprintf(s, sizeof(s), "%s.", token); // Append a period to the sentence
        int L = strlen(s); // Get the length of the sentence

        if (L > 1) {
            if (L > n) {
                printf("Impossible\n");
                return 0; // Exit if the length of the sentence is greater than n
            }
            if (sumL + L + (sumL > 0) > n) {
                ans += 1; // Increment the answer if the sum exceeds n
                sumL = L; // Reset sumL to the current length
            } else {
                sumL += L + (sumL > 0); // Update sumL
            }
        }
        token = strtok(NULL, ".?!"); // Get the next sentence
    }
    printf("%d\n", ans); // Print the final answer
    return 0;
}

// <END-OF-CODE>
