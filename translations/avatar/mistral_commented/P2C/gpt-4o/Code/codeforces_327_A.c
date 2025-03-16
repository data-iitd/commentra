#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the indices of a character in a string
int* find(const char* s, char ch, int* count) {
    int length = strlen(s);
    int* indices = (int*)malloc(length * sizeof(int));
    *count = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == ch) {
            indices[(*count)++] = i;
        }
    }
    return indices;
}

int main() {
    // Read the number of test cases 'n'
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer input

    // Read the string 's'
    char s[100]; // Assuming the string length won't exceed 100 characters
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove the newline character from the string

    // Check if the string 's' does not contain '0' character
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, print the result as the number of test cases minus one
        printf("%d\n", n - 1);
    } else {
        // Find the indices of '0' character in the string 's'
        int count = 0;
        int* indices = find(s, '0', &count);

        // Check if there is only one '0' character in the string 's'
        if (count == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            int ones_count = 0;
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '1') {
                    ones_count++;
                }
            }
            printf("%d\n", n);
        } else {
            // If there are multiple '0's, calculate the maximum combination score
            int maximum = 0;

            // Iterate through each combination of indices of '0' characters
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    // Calculate the score for the current combination
                    int score = 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(i - j) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    if (score > maximum) {
                        maximum = score;
                    }
                }
            }

            // Count the number of '1's in the string
            int ones_count = 0;
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '1') {
                    ones_count++;
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            printf("%d\n", ones_count + maximum);
        }

        // Free the allocated memory for indices
        free(indices);
    }

    return 0;
}

// <END-OF-CODE>
