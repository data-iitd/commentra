#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the first line of input
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Parse the first two integers n and m
    int n, m;
    sscanf(input, "%d %d", &n, &m);

    // Create an array to store the processed strings
    char ans[n][m + 1]; // +1 for the null terminator

    // Iterate through each string in the input
    for (int i = 0; i < n; i++) {
        char str[m + 1]; // +1 for the null terminator
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0; // Remove the newline character

        // Initialize an empty string for the current processed string
        char temp[m + 1]; // +1 for the null terminator
        temp[m] = '\0'; // Set the last character to null terminator

        // Iterate through each character in the string
        for (int j = 0; j < m; j++) {
            if (str[j] == '-') { // If the character is a '-'
                temp[j] = '-'; // Append a '-' character to temp
            } else {
                if ((i + j) % 2 == 1) { // If the index i + j is odd
                    temp[j] = 'W'; // Append 'W' character to temp
                } else {
                    temp[j] = 'B'; // Otherwise, append 'B' character to temp
                }
            }
        }

        // Store the final string in the ans array using the index i
        strcpy(ans[i], temp);
    }

    // Iterate through each string in the ans array and print it
    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
    }

    return 0;
}

// <END-OF-CODE>
