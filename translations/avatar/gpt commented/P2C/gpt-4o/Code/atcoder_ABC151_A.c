#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Flag to enable or disable debugging
bool debug = false;

// Function to log debug messages
void log(const char *text) {
    if (debug) {
        printf("%s\n", text);
    }
}

// Function to parse input from the user or from a string
char parse_input(char *input_string) {
    char c;
    
    // Check if input is provided as a string
    if (input_string == NULL) {
        debug = false;  // Disable debug mode for standard input
        scanf(" %c", &c);  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string and ignore the first and last characters
        char *line = strtok(input_string, "\n");
        line = strtok(NULL, "\n"); // Skip the first line
        line = strtok(NULL, "\n"); // Get the second line
        c = line[0]; // Extract the first character
    }
    
    return c;
}

// Function to solve the problem by finding the next character in the alphabet
char solve(char c) {
    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    char *pos = strchr(alphabet, c);  // Find the position of the given character
    if (pos != NULL && *(pos + 1) != '\0') {
        return *(pos + 1);  // Return the next character in the alphabet
    }
    return '\0'; // Return null character if c is 'z' or not found
}

// Main function to execute the program logic
int main() {
    char result = solve(parse_input(NULL)); // Parse input and solve the problem
    
    // Print the result
    if (result != '\0') {
        printf("%c\n", result); // Print the single result
    } else {
        printf("No next character\n"); // Handle case where there is no next character
    }

    return 0;
}

// <END-OF-CODE>
