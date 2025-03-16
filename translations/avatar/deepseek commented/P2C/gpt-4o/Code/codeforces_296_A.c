#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input representing the threshold

    char input[1000];  // Assuming the input will not exceed 1000 characters
    scanf(" %[^\n]", input);  // Take a space-separated string input

    char *m[100];  // Array to hold the split strings
    int count[100] = {0};  // Array to hold the counts of each unique element
    int uniqueCount = 0;  // To track the number of unique elements

    // Split the input string into tokens
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Check if the token is already counted
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(m[j], token) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        // If the token is new, add it to the list
        if (!found) {
            m[uniqueCount] = token;
            count[uniqueCount] = 1;
            uniqueCount++;
        }
        token = strtok(NULL, " ");
    }

    int possible = 1;  // Initialize a boolean variable to check if the condition is possible

    // Iterate over the unique elements in the list `m`
    for (int i = 0; i < uniqueCount; i++) {
        // Check if the count of the current element is greater than or equal to n / 2 + 1
        if (count[i] >= n / 2 + 1) {
            possible = 0;  // Set possible to False if the condition is met
            break;  // Break the loop as the condition is already not possible
        }
    }

    // Print 'YES' if possible is True, otherwise print 'NO'
    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}

// <END-OF-CODE>
