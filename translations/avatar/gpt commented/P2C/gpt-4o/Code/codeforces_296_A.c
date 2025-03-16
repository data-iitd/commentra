#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read an integer input n which represents the threshold for majority
    int n;
    scanf("%d", &n);
    
    // Read a line of input, split it into a list of strings, and store it in m
    char input[1000]; // Assuming the input will not exceed 1000 characters
    scanf(" %[^\n]", input); // Read the entire line of input
    
    // Tokenize the input string
    char *m[100]; // Assuming a maximum of 100 elements
    int count[100] = {0}; // To count occurrences of each unique element
    int unique_count = 0;
    
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Check if the token is already counted
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(m[j], token) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        // If not found, add it to the list
        if (!found) {
            m[unique_count] = token;
            count[unique_count] = 1;
            unique_count++;
        }
        token = strtok(NULL, " ");
    }

    // Initialize a variable to track if a majority element is possible
    int possible = 1;

    // Iterate through each unique element in the list m
    for (int i = 0; i < unique_count; i++) {
        // Check if the count of the current element is greater than or equal to n/2 + 1
        if (count[i] >= n / 2 + 1) {
            // If it is, set possible to 0 (false) and break the loop
            possible = 0;
            break;
        }
    }

    // Print 'YES' if a majority element is not found, otherwise print 'NO'
    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}

// <END-OF-CODE>
