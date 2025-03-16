
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define a function to log messages when debug mode is enabled
void log(char *text) {
    // Check if debug mode is enabled
    if (debug) {
        // Print the log message
        printf("%s\n", text);
    }
}

// Function to parse input lines
void parse_input(char *lines_as_string) {
    // Set the global debug flag
    global debug;

    // Initialize an empty list to store the lines
    char *lines[100];
    int line_count = 0;

    // If lines_as_string is provided, set debug mode to True and parse lines
    if (lines_as_string!= NULL) {
        debug = true;
        char *line = strtok(lines_as_string, "\n");
        while (line!= NULL) {
            lines[line_count] = line;
            line_count++;
            line = strtok(NULL, "\n");
        }
    }

    // Extract the first character from the first line as the command
    char c = lines[0][0];

    // Call the solve function to get the result
    char result = solve(c);

    // Print the result
    printf("%c\n", result);
}

// Function to solve the problem based on the command
char solve(char c) {
    // Define the alphabet string
    char a[] = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = 0;
    while (a[i]!= c) {
        i++;
    }

    // Return the next character in the alphabet string
    return a[i+1];
}

// Main function to execute the code
int main() {
    // Call the parse_input function to get the result
    parse_input(NULL);

    // Return 0 to indicate successful execution
    return 0;
}

// End of code
