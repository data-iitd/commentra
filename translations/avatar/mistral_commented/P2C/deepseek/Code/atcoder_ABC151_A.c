#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global debug flag
bool debug = false;

// Function to log messages when debug mode is enabled
void log(char* text) {
    if (debug) {
        printf("%s\n", text);
    }
}

// Function to parse input lines
char* parse_input(char* lines_as_string) {
    // Set the global debug flag
    debug = true;

    // Initialize a variable to store the command
    char command[100];

    // Extract the first character from the first line as the command
    sscanf(lines_as_string, "%s", command);

    // Return the command as a string
    return command;
}

// Function to solve the problem based on the command
char solve(char c) {
    // Define the alphabet string
    char a[] = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = 0;
    while (a[i] != '\0' && a[i] != c) {
        i++;
    }

    // Return the next character in the alphabet string
    if (a[i+1] != '\0') {
        return a[i+1];
    } else {
        return '\0'; // Return null character if no next character
    }
}

// Main function to execute the code
int main() {
    // Read input lines as a single string
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Call the parse_input function to get the command
    char* command = parse_input(input);

    // Call the solve function to get the result
    char result = solve(command[0]);

    // Print the result
    printf("%c\n", result);

    return 0;
}
