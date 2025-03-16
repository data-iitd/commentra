#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100 // Define a maximum number of strings
#define MAX_LENGTH 100  // Define a maximum length for each string

int main() {
    int N;
    scanf("%d", &N); // Reading the number of strings from the input

    char strings[MAX_STRINGS][MAX_LENGTH]; // Array to store strings
    int past[MAX_STRINGS] = {0}; // Array to track if a string has been seen before
    int ans = 1; // Initializing a boolean variable to store the result of the check
    char next = '\0'; // Variable to store the last character of the previous string

    // Loop to read strings from the input and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%s", strings[i]);
    }

    // Loop to check for the condition
    for (int i = 0; i < N; i++) {
        // Check if the current string has been seen before
        for (int j = 0; j < i; j++) {
            if (strcmp(strings[i], strings[j]) == 0) {
                ans = 0; // Set ans to false
                break;
            }
        }
        if (ans == 0) break; // Break if a duplicate is found

        // Check if it's not the first iteration of the loop
        if (i != 0) {
            // Check if the current string starts with the same character as the previous string
            if (strings[i][0] != next) {
                ans = 0; // Set ans to false
                break;
            }
        }
        // Store the last character of the current string
        next = strings[i][strlen(strings[i]) - 1];
    }

    // Print "Yes" if the condition is satisfied
    if (ans) {
        printf("Yes\n");
    } else { // Print "No" if the condition is not satisfied
        printf("No\n");
    }

    return 0;
}
