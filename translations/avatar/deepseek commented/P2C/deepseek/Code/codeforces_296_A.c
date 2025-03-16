#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input representing the threshold

    char m[1000];  // Assuming the input string length won't exceed 1000 characters
    scanf(" %[^\n]", m);  // Take a space-separated string input and store it in `m`

    int possible = 1;  // Initialize an integer variable to check if the condition is possible

    // Split the input string into a list (array of strings) dynamically
    char *token = strtok(m, " ");
    char *tokens[1000];  // Array to store the tokens
    int token_count = 0;

    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    // Convert the tokens array to a unique elements array
    char unique_elements[1000][100];
    int unique_count = 0;

    for (int i = 0; i < token_count; i++) {
        int is_unique = 1;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(tokens[i], unique_elements[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strcpy(unique_elements[unique_count++], tokens[i]);
        }
    }

    // Iterate over the unique elements in the unique_elements array
    for (int i = 0; i < unique_count; i++) {
        // Check if the count of the current element is greater than or equal to n / 2 + 1
        int count = 0;
        for (int j = 0; j < token_count; j++) {
            if (strcmp(unique_elements[i], tokens[j]) == 0) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
            possible = 0;  // Set possible to False if the condition is met
            break;  // Break the loop as the condition is already not possible
        }
    }

    // Print 'YES' if possible is True, otherwise print 'NO'
    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}
