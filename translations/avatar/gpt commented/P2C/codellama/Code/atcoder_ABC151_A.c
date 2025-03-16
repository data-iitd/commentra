
#include <stdio.h>
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
    global debug;
    char* lines = NULL;
    
    // Check if input is provided as a string
    if (lines_as_string == NULL) {
        debug = false;  // Disable debug mode for standard input
        lines = (char*)malloc(sizeof(char) * 100);  // Allocate memory for the input
        scanf("%s", lines);  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        lines = strtok(lines_as_string, "\n");
    }
    
    // Extract the first element from the first line as the character to process
    char* c = strtok(lines, " ");
    return c;
}

// Function to solve the problem by finding the next character in the alphabet
char* solve(char* c) {
    char* a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i = strchr(a, c) - a;  // Find the index of the given character
    return a + i + 1;  // Return the next character in the alphabet
}

// Main function to execute the program logic
void main() {
    // Parse input and solve the problem
    char* result = solve(parse_input(NULL));
    
    // Check if the result is a list and print each result
    if (isinstance(result, list)) {
        for (int i = 0; i < strlen(result); i++) {
            printf("%c", result[i]);
        }
    } else {
        // Print the single result
        printf("%s", result);
    }
}

// Entry point of the program
int main(int argc, char** argv) {
    main();
    return 0;
}

