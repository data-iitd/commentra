#include <stdio.h>
#include <string.h>

int debug = 0;

// Function to log messages if debug is enabled
void log_message(const char *text) {
    if (debug) {
        printf("%s\n", text);
    }
}

// Function to parse input from either user input or a string
char parse_input(char *c) {
    if (debug) {
        // In a real scenario, you would handle string input here
        // For simplicity, we will just read from standard input
        printf("Enter a character: ");
        scanf(" %c", c);
    } else {
        // In debug mode, we would parse from a string
        // For this example, we will just read from standard input
        printf("Enter a character: ");
        scanf(" %c", c);
    }
    return *c;
}

// Function to solve the problem by finding the next character in the alphabet
char solve(char c) {
    if (c >= 'a' && c < 'z') {
        return c + 1; // Return the next character
    } else if (c == 'z') {
        return 'a'; // Wrap around to 'a'
    } else {
        return c; // Return the same character if it's not a lowercase letter
    }
}

// Main function to orchestrate the execution of the program
int main() {
    char c;
    parse_input(&c);
    char result = solve(c);
    printf("%c\n", result);
    return 0;
}

// <END-OF-CODE>
