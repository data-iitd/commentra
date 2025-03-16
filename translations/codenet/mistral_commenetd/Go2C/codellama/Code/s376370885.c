
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom scanner type that wraps bufio.Scanner
typedef struct Scanner {
    struct bufio_Scanner *Scanner;
} Scanner;

// Initialize a new Scanner instance with the given reader and maximum buffer size
Scanner *NewScanner(FILE *r, int max) {
    struct bufio_Scanner *s = bufio_NewScanner(r); // Create a new bufio.Scanner instance
    s->split = scanWords; // Set the split function to scanWords
    if (max <= 0) {
        max = 1048576; // Set a default maximum buffer size if none is provided
    }
    s->buffer = (char *)malloc(max); // Set the buffer size
    return &(Scanner){s}; // Return the Scanner instance
}

// Parse an integer from the current scanner data
int Scanner_Int(Scanner *s) {
    s->Scanner->scan(s->Scanner); // Scan the next token from the input
    char *end;
    long i = strtol(s->Scanner->token, &end, 10); // Parse the token as an integer
    if (*end != '\0') {
        exit(1); // Panic if there was an error parsing the token
    }
    return (int)i; // Return the parsed integer
}

// Check if a byte is a whitespace character
int isSpace(char b) {
    return b == ' ' || b == '\n' || b == '\r' || b == '\t';
}

// Split input data into tokens using scanWords function
int scanWords(char *data, int atEOF) {
    int start = 0; // Initialize start index of the token
    while (start < strlen(data) && isSpace(data[start])) {
        start++; // Increment start index while reading whitespace characters
    }
    for (int i = start; i < strlen(data); i++) {
        if (isSpace(data[i])) {
            return i + 1; // Return the token and advance index if a whitespace character is found
        }
    }
    if (atEOF && strlen(data) > start) { // If we've reached the end of the input and there are still characters left in the buffer
        return strlen(data); // Return the remaining characters as the token
    }
    return start; // Return an empty token and advance index if no token was found
}

// Print a line to the console with the given arguments
void Pln(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

// Entry point of the program
int main() {
    // Read two integers n and k from standard input
    int n = Scanner_Int(NewScanner(stdin, 0));
    int k = Scanner_Int(NewScanner(stdin, 0));
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        Pln(0);
    } else {
        // If n is not divisible by k, print 1 to the console
        Pln(1);
    }
    return 0;
}

