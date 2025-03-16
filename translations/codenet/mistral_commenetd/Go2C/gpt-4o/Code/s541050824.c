// Importing required headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializing variables
FILE *input = stdin;
FILE *output = stdout;

// Function to read a line from standard input
char* readLine() {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, input);
    return line;
}

// Function to write to standard output
void writeOutput(const char *outputStr) {
    fprintf(output, "%s", outputStr);
}

int main() {
    // Example usage of readLine and writeOutput
    char *line = readLine();
    writeOutput(line);
    free(line); // Free the allocated memory for the line
    return 0;
}

// <END-OF-CODE>
