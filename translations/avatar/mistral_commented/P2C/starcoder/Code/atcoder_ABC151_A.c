#include <stdio.h>
#include <stdlib.h>
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
    char **lines = NULL;

    // If lines_as_string is provided, set debug mode to True and parse lines
    if (lines_as_string!= NULL) {
        debug = 1;
        lines = malloc(sizeof(char *) * (strlen(lines_as_string) + 1));
        int i = 0;
        for (int j = 0; j < strlen(lines_as_string); j++) {
            if (lines_as_string[j] == '\n') {
                lines[i] = malloc(sizeof(char) * (j - i + 1));
                for (int k = i; k < j; k++) {
                    lines[i][k - i] = lines_as_string[k];
                }
                lines[i][j - i] = '\0';
                i = j + 1;
            }
        }
        lines[i] = NULL;
    }

    // Extract the first character from the first line as the command
    char c = lines[0][0];

    // Return the command as a tuple
    return (c, lines);
}

// Function to solve the problem based on the command
char *solve(char c) {
    // Define the alphabet string
    char *a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = strchr(a, c) - a;

    // Return the next character in the alphabet string
    return a[i + 1];
}

// Main function to execute the code
int main(int argc, char *argv[]) {
    // Call the parse_input function to get the command
    char *result = solve(*parse_input(argv[1]));

    // Check if the result is a list or a single string
    if (result[0] == '[') {
        // If it's a list, print each element separately
        int i = 1;
        while (result[i]!= ']') {
            printf("%c", result[i]);
            i++;
        }
    } else {
        // If it's a single string, print it directly
        printf("%s", result);
    }

    // Free the memory allocated for the lines
    if (lines!= NULL) {
        for (int i = 0; lines[i]!= NULL; i++) {
            free(lines[i]);
        }
        free(lines);
    }

    // Return success
    return EXIT_SUCCESS;
}

