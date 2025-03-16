
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    // (Scanner object not available in C, so we'll use a simple input method)
    int N; 
    scanf("%d", &N);  // Read the number of strings to be processed
    
    // Initialize a HashMap to store the strings with their corresponding indices
    char** strings = (char**)malloc(N * sizeof(char*)); 
    for (int i = 0; i < N; i++) { 
        strings[i] = (char*)malloc(100 * sizeof(char)); // Assuming each string is at most 100 characters long
        scanf("%s", strings[i]); // Read N strings from the input and store them in the map
    } 
    
    // Initialize a boolean variable to track if the conditions are met
    int ans = 1;  // Initialize ans to 1 (true)
    
    // Initialize a HashMap to keep track of previously seen strings
    char** past = (char**)malloc(N * sizeof(char*)); 
    for (int i = 0; i < N; i++) { 
        past[i] = (char*)malloc(100 * sizeof(char)); // Assuming each string is at most 100 characters long
    } 
    
    // Variable to hold the last character of the previous string
    char next[100]; // Assuming each string is at most 100 characters long
    next[0] = '\0'; // Initialize next to an empty string
    
    // Iterate through the strings to check the conditions
    for (int i = 0; i < N; i++) { 
        // Check if the current string has already been seen
        int found = 0; 
        for (int j = 0; j < i; j++) { 
            if (strcmp(strings[i], past[j]) == 0) { 
                found = 1; // Set found to 1 if a duplicate is found
                break; 
            } 
        } 
        if (found) { 
            ans = 0; // Set ans to 0 (false) if a duplicate is found
            break; 
        } 
        
        // Store the current string in the past map
        strcpy(past[i], strings[i]); 
        
        // Check if this is not the first string
        if (i!= 0) { 
            // Check if the first character of the current string matches the last character of the previous string
            if (strings[i][0]!= next[0]) { 
                ans = 0; // Set ans to 0 (false) if the characters do not match
                break; 
            } 
        } 
        
        // Update 'next' to the last character of the current string
        strcpy(next, &strings[i][strlen(strings[i]) - 1]); 
    } 
    
    // Output the result based on the value of ans
    if (ans) { 
        printf("Yes\n"); // Print "Yes" if all conditions are satisfied
    } else { 
        printf("No\n"); // Print "No" if any condition fails
    } 
    
    // Free the memory allocated for strings and past
    for (int i = 0; i < N; i++) { 
        free(strings[i]); 
        free(past[i]); 
    } 
    free(strings); 
    free(past); 
    
    return 0; 
}
