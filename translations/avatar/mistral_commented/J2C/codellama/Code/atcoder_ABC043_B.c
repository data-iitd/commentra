
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Input stream to read input from the console
FILE *inputStream = stdin;

// Output stream to write output to the console
FILE *outputStream = stdout;

// Class for reading input
typedef struct {
    char *line;
    int lineLength;
    int lineCapacity;
    int tokenIndex;
    char *token;
    int tokenLength;
    int tokenCapacity;
} LightScanner;

// Initialize the LightScanner for reading input
void lightScannerInit(LightScanner *scanner) {
    scanner->line = NULL;
    scanner->lineLength = 0;
    scanner->lineCapacity = 0;
    scanner->tokenIndex = 0;
    scanner->token = NULL;
    scanner->tokenLength = 0;
    scanner->tokenCapacity = 0;
}

// Read a new line from the input stream
void lightScannerReadLine(LightScanner *scanner) {
    if (scanner->line != NULL) { // If there is a line in the scanner
        free(scanner->line); // Free the line
    }
    scanner->line = NULL;
    scanner->lineLength = 0;
    scanner->lineCapacity = 0;
    scanner->tokenIndex = 0;
    scanner->token = NULL;
    scanner->tokenLength = 0;
    scanner->tokenCapacity = 0;

    int c; // Character read from the input stream
    while ((c = fgetc(inputStream)) != EOF) { // While there is more input
        if (c == '\n') { // If the character is a newline
            break; // Break out of the loop
        }
        if (scanner->lineLength == scanner->lineCapacity) { // If the line is full
            scanner->lineCapacity = scanner->lineCapacity == 0 ? 1 : scanner->lineCapacity * 2; // Double the capacity
            scanner->line = realloc(scanner->line, scanner->lineCapacity); // Reallocate the line
        }
        scanner->line[scanner->lineLength++] = c; // Add the character to the line
    }
    scanner->line[scanner->lineLength] = '\0'; // Add a null terminator to the line
}

// Get the next token from the input stream
void lightScannerNextToken(LightScanner *scanner) {
    if (scanner->token != NULL) { // If there is a token in the scanner
        free(scanner->token); // Free the token
    }
    scanner->token = NULL;
    scanner->tokenLength = 0;
    scanner->tokenCapacity = 0;

    while (scanner->tokenIndex < scanner->lineLength) { // While there is more input
        char c = scanner->line[scanner->tokenIndex++]; // Get the next character
        if (c == ' ' || c == '\t' || c == '\n') { // If the character is a space, tab, or newline
            break; // Break out of the loop
        }
        if (scanner->tokenLength == scanner->tokenCapacity) { // If the token is full
            scanner->tokenCapacity = scanner->tokenCapacity == 0 ? 1 : scanner->tokenCapacity * 2; // Double the capacity
            scanner->token = realloc(scanner->token, scanner->tokenCapacity); // Reallocate the token
        }
        scanner->token[scanner->tokenLength++] = c; // Add the character to the token
    }
    scanner->token[scanner->tokenLength] = '\0'; // Add a null terminator to the token
}

// Get the next token from the input stream
char *lightScannerString(LightScanner *scanner) {
    return scanner->token;
}

// Static class for solving the problem
typedef struct {
    int testNumber;
} BUnhappyHackingABCEdit;

// Initialize the solver with the given input and output streams
void bUnhappyHackingABCEditInit(BUnhappyHackingABCEdit *solver, int testNumber, LightScanner *in, FILE *out) {
    solver->testNumber = testNumber;
}

// Solve the problem with the given input and output streams
void bUnhappyHackingABCEditSolve(BUnhappyHackingABCEdit *solver, LightScanner *in, FILE *out) {
    char *s = lightScannerString(in); // Read the input string
    char *d = malloc(strlen(s) + 1); // Initialize an empty string for the output
    int dLength = 0; // Length of the output string

    for (int i = 0; i < strlen(s); i++) { // Iterate through each character in the input string
        switch (s[i]) { // Switch statement to handle different characters
            case '0':
                d[dLength++] = '0'; // Append "0" to the output string
                break;
            case '1':
                d[dLength++] = '1'; // Append "1" to the output string
                break;
            case 'B':
                if (dLength > 0) { // If there is a character in the output string
                    dLength--; // Remove the last character from the output string
                }
                break;
        }
    }
    d[dLength] = '\0'; // Add a null terminator to the output string

    fprintf(out, "%s\n", d); // Print the output string to the console
}

int main() {
    LightScanner in; // Initialize the LightScanner for reading input
    lightScannerInit(&in); // Initialize the LightScanner

    BUnhappyHackingABCEdit solver; // Initialize the solver
    bUnhappyHackingABCEditInit(&solver, 1, &in, outputStream); // Initialize the solver with the given input and output streams

    bUnhappyHackingABCEditSolve(&solver, &in, outputStream); // Run the solver with the given input and output streams

    return 0;
}

