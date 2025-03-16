#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Flag to enable or disable debugging
bool debug = false;

// Function to log debug messages
void log(char* text) {
    if (debug) {
        printf("%s\n", text);
    }
}

// Function to parse input from the user or from a string
char* parse_input(char* lines_as_string) {
    static char lines[1000];
    if (lines_as_string == NULL) {
        debug = false;  // Disable debug mode for standard input
        fgets(lines, sizeof(lines), stdin);  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        strncpy(lines, lines_as_string, sizeof(lines));
        // Remove the first and last lines
        char* newline = strchr(lines, '\n');
        if (newline) {
            *newline = '\0';
        }
        newline = strchr(lines, '\n');
        if (newline) {
            memmove(lines, newline + 1, strlen(newline) + 1);
        }
    }
    // Extract the first element from the first line as the character to process
    char* token = strtok(lines, " ");
    return token;
}

// Function to solve the problem by finding the next character in the alphabet
char solve(char c) {
    char a[] = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i = 0;
    while (a[i] != '\0' && a[i] != c) {
        i++;
    }
    if (a[i] == '\0') {
        return '\0';  // Character not found
    }
    return a[i + 1];  // Return the next character in the alphabet
}

// Main function to execute the program logic
int main() {
    // Parse input and solve the problem
    char* input = parse_input(NULL);
    char result = solve(input[0]);
    
    // Print the result
    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
