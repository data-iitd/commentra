#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    debug = true;

    // Initialize an empty list to store the lines
    char *lines[100];

    // If lines_as_string is provided, set debug mode to True and parse lines
    if (lines_as_string != NULL) {
        // Split the lines by newline character
        char *line = strtok(lines_as_string, "\n");

        // Iterate over the lines
        while (line != NULL) {
            // Add the line to the list
            lines[i++] = line;

            // Get the next line
            line = strtok(NULL, "\n");
        }
    }

    // Extract the first character from the first line as the command
    char c = lines[0][0];

    // Return the command as a tuple
    return (c,);
}

// Function to solve the problem based on the command
char solve(char c) {
    // Define the alphabet string
    char a[] = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = strchr(a, c) - a;

    // Return the next character in the alphabet string
    return a[i+1];
}

// Main function to execute the code
void main() {
    // Call the parse_input function to get the command
    char c = solve(*parse_input());

    // Check if the result is a list or a single string
    if (isinstance(result, list)) {
        // If it's a list, print each element separately
        for (int i = 0; i < sizeof(result); i++) {
            printf("%s\n", result[i]);
        }
    } else {
        // If it's a single string, print it directly
        printf("%s\n", result);
    }
}

// Run the main function if the script is executed directly
if (__name__ == '__main__') {
    main();
}

