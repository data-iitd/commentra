#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Custom scanner struct to read input
typedef struct {
    FILE *file;
    int bufferSize;
    char *buffer;
    size_t bufferIndex;
} Scanner;

// Initialize a new Scanner for reading input from standard input (stdin)
Scanner* newScanner(FILE *file, int bufferSize) {
    Scanner *scanner = (Scanner*)malloc(sizeof(Scanner));
    scanner->file = file;
    scanner->bufferSize = bufferSize;
    scanner->buffer = (char*)malloc(bufferSize * sizeof(char));
    scanner->bufferIndex = 0;
    return scanner;
}

// Read the next token from the input and convert it to an integer
int scanInt(Scanner *scanner) {
    int num;
    fscanf(scanner->file, "%d", &num);
    return num;
}

// Check if a character is a whitespace character
int isSpace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

// Custom split function to tokenize input
int scanWords(char *data, int *advance, char **token, int atEOF) {
    int start = *advance;
    // Skip leading whitespace
    while (start < strlen(data) && isSpace(data[start])) {
        start++;
    }
    // Find the end of the next word
    for (int i = start; i < strlen(data); i++) {
        if (isSpace(data[i])) {
            *advance = i + 1;
            *token = (char*)malloc((i - start + 1) * sizeof(char));
            strncpy(*token, data + start, i - start);
            (*token)[i - start] = '\0';
            return 1; // Return the word found
        }
    }
    // If at EOF and there is data left, return the last word
    if (atEOF && start < strlen(data)) {
        *advance = strlen(data);
        *token = (char*)malloc((strlen(data) - start + 1) * sizeof(char));
        strcpy(*token, data + start);
        return 1;
    }
    *advance = start;
    return 0; // Return the current position if no word is found
}

// Print a line to standard output
void pln(int s) {
    printf("%d\n", s);
}

int main() {
    // Initialize a new Scanner for reading input from standard input (stdin)
    Scanner *scanner = newScanner(stdin, 0);

    // Read two integers n and k from the input
    int n = scanInt(scanner);
    int k = scanInt(scanner);

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        pln(0);
    } else {
        // If n is not divisible by k, print 1
        pln(1);
    }

    // Free allocated memory
    free(scanner->buffer);
    free(scanner);

    return 0;
}
