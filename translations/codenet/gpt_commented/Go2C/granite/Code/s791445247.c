
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a Scanner struct to wrap bufio.Scanner for custom functionality
typedef struct Scanner {
    char *buf; // Buffer to store input
    int cap; // Capacity of the buffer
    int len; // Length of the input
    int pos; // Current position in the buffer
} Scanner;

// Initialize a new Scanner with a specified buffer size
Scanner *newScanner(FILE *r, int max) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner)); // Allocate memory for the Scanner
    s->buf = (char *)malloc(max * sizeof(char)); // Allocate memory for the buffer
    s->cap = max; // Set the capacity of the buffer
    s->len = 0; // Set the length of the input to 0
    s->pos = 0; // Set the current position in the buffer to 0
    return s; // Return the new Scanner instance
}

// Int reads the next token from the input and converts it to an integer
int intScan(Scanner *s) {
    char *end; // Pointer to store the end of the token
    int n = strtol(s->buf + s->pos, &end, 10); // Convert the token to an integer
    s->pos += end - (s->buf + s->pos); // Update the current position in the buffer
    return n; // Return the parsed integer
}

// isSpace checks if a character is a whitespace character
int isSpace(char c) {
    return c =='' || c == '\n' || c == '\r' || c == '\t'; // Return true for whitespace
}

// scanWords is a split function for bufio.Scanner that splits input into words
int scanWords(Scanner *s) {
    int start = s->pos; // Store the current position in the buffer
    // Skip leading whitespace
    while (isSpace(s->buf[s->pos])) {
        s->pos++; // Increment the current position in the buffer
    }
    // Find the end of the next word
    while (s->pos < s->len &&!isSpace(s->buf[s->pos])) {
        s->pos++; // Increment the current position in the buffer
    }
    // Return the word and advance position
    return s->pos;
}

// Pln is a helper function to print a line with a newline
void Pln(int n,...) {
    va_list args; // Variable argument list
    va_start(args, n); // Initialize the variable argument list
    for (int i = 0; i < n; i++) {
        printf("%s", va_arg(args, char *)); // Print each argument
    }
    printf("\n"); // Print a newline
    va_end(args); // Clean up the variable argument list
}

int main() {
    Scanner *s = newScanner(stdin, 1048576); // Initialize a new Scanner with a buffer size of 1048576
    int n = intScan(s); // Read the first integer from input
    int k = intScan(s); // Read the second integer from input
    if (n % k == 0) {
        Pln(1, "0"); // Print 0 if n is divisible by k
    } else {
        Pln(1, "1"); // Print 1 if n is not divisible by k
    }
    return 0;
}

// END-OF-CODE