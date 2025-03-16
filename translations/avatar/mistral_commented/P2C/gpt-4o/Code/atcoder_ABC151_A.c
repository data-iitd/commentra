#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Global debug flag
bool debug = false;

// Function to log messages when debug mode is enabled
void log(const char *text) {
    // Check if debug mode is enabled
    if (debug) {
        // Print the log message
        printf("%s\n", text);
    }
}

// Function to parse input lines
void parse_input(const char *lines_as_string, char *command) {
    // Set debug mode to true if lines_as_string is provided
    if (lines_as_string != NULL) {
        debug = true;

        // Split the input string into lines
        char *lines = strdup(lines_as_string);
        char *line = strtok(lines, "\n");

        // Get the first line and extract the command
        if (line != NULL) {
            sscanf(line, "%s", command);
        }

        free(lines);
    }
}

// Function to solve the problem based on the command
char solve(char c) {
    // Define the alphabet string
    const char *a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    char *pos = strchr(a, c);
    if (pos != NULL && pos + 1 != NULL) {
        return *(pos + 1); // Return the next character in the alphabet string
    }
    return '\0'; // Return null character if not found
}

// Main function to execute the code
int main() {
    char command[2]; // To hold the command character
    parse_input("a\n", command); // Example input, replace with actual input as needed

    // Call the solve function to get the result
    char result = solve(command[0]);

    // Print the result
    if (result != '\0') {
        printf("%c\n", result);
    }

    return 0;
}

// <END-OF-CODE>
