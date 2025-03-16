#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the first line of input
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // Parse the first two elements of the input as integers n and m
    int n = atoi(strtok(input, " "));
    int m = atoi(strtok(NULL, " "));
    
    // Initialize an array to hold the resulting strings
    char ans[n][m + 1]; // +1 for the null terminator
    
    // Loop through each of the n lines of input
    for (int i = 0; i < n; i++) {
        // Read the current line of input
        char str[100];
        fgets(str, sizeof(str), stdin);
        
        // Remove the newline character from the end of the string if present
        str[strcspn(str, "\n")] = 0;
        
        // Create a temporary string to construct the output for the current line
        char temp[m + 1]; // +1 for the null terminator
        temp[m] = '\0'; // Set the last character to null terminator
        
        // Loop through each character in the current line
        for (int j = 0; j < m; j++) {
            // Check if the character is a '-'
            if (str[j] == '-') {
                // Append '-' to the temp string if it is
                temp[j] = '-';
            } else {
                // If the character is not '-', determine whether to append 'W' or 'B'
                if ((i + j) % 2 == 1) {
                    temp[j] = 'W'; // Append 'W' for odd indices
                } else {
                    temp[j] = 'B'; // Append 'B' for even indices
                }
            }
        }
        // Store the constructed string in the ans array
        strcpy(ans[i], temp);
    }
    
    // Output the resulting strings line by line
    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
    }
    
    return 0;
}
// <END-OF-CODE>
