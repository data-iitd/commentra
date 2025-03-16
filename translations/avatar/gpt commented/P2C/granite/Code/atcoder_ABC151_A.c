
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    char* lines[100];
    int line_count = 0;
    
    // Check if input is provided as a string
    if (lines_as_string == NULL) {
        debug = false;  // Disable debug mode for standard input
        char input[100];
        fgets(input, 100, stdin);  // Read input from the user
        lines[line_count++] = input;
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        char* token = strtok(lines_as_string, "\n");
        while (token!= NULL) {
            lines[line_count++] = token;
            token = strtok(NULL, "\n");
        }
    }
    
    // Extract the first element from the first line as the character to process
    char* c = strtok(lines[0], " ");
    return c;
}

// Function to solve the problem by finding the next character in the alphabet
char* solve(char* c) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i;
    for (i = 0; i < strlen(alphabet); i++) {
        if (alphabet[i] == c[0]) {
            break;
        }
    }
    return &alphabet[i + 1];  // Return the next character in the alphabet
}

// Main function to execute the program logic
int main() {
    // Parse input and solve the problem
    char* result = solve(parse_input(NULL));
    
    // Check if the result is a list and print each result
    if (result[0] == '[') {
        char* token = strtok(result, ",");
        while (token!= NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    } else {
        // Print the single result
        printf("%s\n", result);
    }
    
    return 0;
}

// Entry point of the program
int main() {
    return 0;
}
