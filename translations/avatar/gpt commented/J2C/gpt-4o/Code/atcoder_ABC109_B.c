#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main() {
    // Read the number of strings to be processed
    int N;
    scanf("%d", &N);
    
    // Initialize an array to store the strings
    char strings[MAX_STRINGS][MAX_LENGTH];
    
    // Read N strings from the input
    for (int i = 0; i < N; i++) {
        scanf("%s", strings[i]);
    }
    
    // Initialize a boolean variable to track if the conditions are met
    int ans = 1; // 1 for true, 0 for false
    
    // Variable to hold the last character of the previous string
    char next = '\0';
    
    // Iterate through the strings to check the conditions
    for (int i = 0; i < N; i++) {
        // Check for duplicates
        for (int j = 0; j < i; j++) {
            if (strcmp(strings[i], strings[j]) == 0) {
                ans = 0; // Set answer to false if a duplicate is found
                break;
            }
        }
        
        if (ans == 0) {
            break; // Exit if a duplicate was found
        }
        
        // Check if this is not the first string
        if (i != 0) {
            // Check if the first character of the current string matches the last character of the previous string
            if (next != strings[i][0]) {
                ans = 0; // Set answer to false if the characters do not match
                break;
            }
        }
        
        // Update 'next' to the last character of the current string
        next = strings[i][strlen(strings[i]) - 1];
    }
    
    // Output the result based on the value of ans
    if (ans) {
        printf("Yes\n"); // Print "Yes" if all conditions are satisfied
    } else {
        printf("No\n"); // Print "No" if any condition fails
    }
    
    return 0;
}
