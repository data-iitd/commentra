#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a helper function 'find' to locate the indices of a character in a string
int* find(const char* s, char ch, int* len) {
    // Allocate memory for the indices array
    int* indices = (int*)malloc(strlen(s) * sizeof(int));
    *len = 0;

    // Use a loop to find the indices where the character 'ch' appears in the string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            indices[*len] = i;
            (*len)++;
        }
    }

    return indices;
}

int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    scanf("%d", &n);

    // Read the string 's' from the standard input and remove any leading or trailing whitespaces
    char s[100001];
    scanf("%s", s);

    // Check if the string 's' does not contain '0' character
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, print the result as the number of test cases minus one
        printf("%d\n", n - 1);
    } else {
        // Find the indices of '0' character in the string 's'
        int len;
        int* indices = find(s, '0', &len);

        // Check if there is only one '0' character in the string 's'
        if (len == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            printf("%d\n", n);
        } else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    // Calculate the score for the current combination using the given formula
                    int score = 2 + 2 * (abs(i - j) - 1) - (abs(indices[i] - indices[j]) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    if (score > maximum) {
                        maximum = score;
                    }
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            printf("%d\n", (int)strlen(s) - len + maximum);

            // Free the allocated memory for the indices array
            free(indices);
        }
    }

    return 0;
}
