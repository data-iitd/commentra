#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a helper function 'find' to locate the indices of a character in a string
int* find(char* s, char ch) {
    // Use a dynamic array to store the indices of the character 'ch' in the string 's'
    int* indices = (int*)malloc(sizeof(int) * strlen(s));
    // Initialize the number of indices as 0
    int n = 0;
    // Iterate through each character in the string 's'
    for (int i = 0; i < strlen(s); i++) {
        // Check if the current character is the character 'ch'
        if (s[i] == ch) {
            // If the current character is the character 'ch', add its index to the dynamic array
            indices[n++] = i;
        }
    }
    // Return the dynamic array
    return indices;
}

// Check if the given input is valid and execute the main logic if it is
int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    scanf("%d", &n);

    // Read the string 's' from the standard input and remove any leading or trailing whitespaces
    char* s = (char*)malloc(sizeof(char) * 1000);
    scanf("%s", s);
    s = strtok(s, " ");

    // Check if the string 's' does not contain '0' character
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, print the result as the number of test cases minus one
        printf("%d\n", n - 1);
    }

    // If '0' is present, proceed with further logic
    else {
        // Find the indices of '0' character in the string 's'
        int* indices = find(s, '0');

        // Check if there is only one '0' character in the string 's'
        if (strlen(indices) == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            printf("%d\n", n);
        }

        // If there are multiple '0's, calculate the maximum combination score
        else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using itertools.combinations()
            int* combs = (int*)malloc(sizeof(int) * strlen(s) * (strlen(s) - 1) / 2);
            int n = 0;
            for (int i = 0; i < strlen(s); i++) {
                for (int j = i + 1; j < strlen(s); j++) {
                    combs[n++] = i;
                    combs[n++] = j;
                }
            }

            // Iterate through each combination and calculate the score for that combination
            for (int i = 0; i < n; i += 2) {
                // Calculate the score for the current combination using the given formula
                int score = 2 + 2 * (abs(indices[i] - indices[i + 1]) - 1) - (abs(combs[i] - combs[i + 1]) - 1);
                // Update the maximum combination score if the current combination score is greater
                maximum = maximum > score ? maximum : score;
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            printf("%d\n", strlen(s) - strlen(indices) + maximum);
        }
    }
    return 0;
}

