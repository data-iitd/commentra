

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner for reading input
Scanner in;

int main() {
    // Read the first two integers from the standard input
    int n = in.Int();
    int k = in.Int();

    // Check if n is divisible by k
    if (n % k == 0) {
        // If it is, print 0
        printf("0\n");
    } else {
        // If not, print 1
        printf("1\n");
    }
}

// Define a new Scanner type
typedef struct Scanner {
    char *buf;
    int len;
    int cap;
    char *ptr;
} Scanner;

// Create a new Scanner instance
Scanner NewScanner(FILE *r) {
    // Initialize a new Scanner instance
    Scanner s;
    s.buf = (char *)malloc(1048576);
    s.len = 0;
    s.cap = 1048576;
    s.ptr = s.buf;
    return s;
}

// Parse an integer from a string
int Int(Scanner *s) {
    // Read the next token as a string
    char *token = s->ptr;
    while (*s->ptr!='' && *s->ptr!= '\n' && *s->ptr!= '\r' && *s->ptr!= '\t' && *s->ptr!= '\0') {
        s->ptr++;
    }
    *s->ptr = '\0';
    s->ptr++;
    // Parse the string to an integer and return it
    int i = atoi(token);
    return i;
}

// Check if a byte is a whitespace character
int isSpace(char c) {
    // Return true if the byte is a space, newline, carriage return, or tab character
    return c =='' || c == '\n' || c == '\r' || c == '\t';
}

// Split function for bufio.Scanner to split on words instead of whitespace
void scanWords(Scanner *s) {
    // Initialize the start index
    int start = 0;
    // Find the first non-whitespace character
    while (start < s->len && isSpace(s->buf[start])) {
        start++;
    }
    // Iterate through the data and find the next whitespace character or end of data
    for (int i = start; i < s->len; i++) {
        // If the current character is a whitespace character, return the token and advance the index
        if (isSpace(s->buf[i])) {
            s->buf[i] = '\0';
            s->ptr = s->buf + i + 1;
            return;
        }
    }
}

// Print a line with the given arguments
void Pln(int n,...) {
    // Print the line with the given arguments
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%s", va_arg(args, char *));
    }
    printf("\n");
    va_end(args);
}

// End of code
