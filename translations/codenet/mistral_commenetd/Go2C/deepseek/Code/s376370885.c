#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a custom scanner type that wraps bufio.Scanner
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t pos;
} Scanner;

// Initialize a new Scanner instance with the given reader and maximum buffer size
Scanner* NewScanner(FILE *file, size_t max) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buffer_size = max;
    s->buffer = (char *)malloc(max);
    s->pos = 0;
    fread(s->buffer, 1, max, file);
    return s;
}

// Parse an integer from the current scanner data
int Scanner_Int(Scanner *s) {
    while (s->pos < s->buffer_size && isspace(s->buffer[s->pos])) {
        s->pos++;
    }
    int result = 0;
    while (s->pos < s->buffer_size && isdigit(s->buffer[s->pos])) {
        result = result * 10 + (s->buffer[s->pos] - '0');
        s->pos++;
    }
    return result;
}

// Check if a byte is a whitespace character
int isSpace(char b) {
    return b == ' ' || b == '\n' || b == '\r' || b == '\t';
}

// Print a line to the console with the given arguments
void Pln(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

// Entry point of the program
int main() {
    // Read two integers n and k from standard input
    FILE *file = fopen("input.txt", "r");
    Scanner *in = NewScanner(file, 1048576);
    int n = Scanner_Int(in);
    int k = Scanner_Int(in);
    fclose(file);

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        Pln("0");
    } else {
        // If n is not divisible by k, print 1 to the console
        Pln("1");
    }

    // Free the allocated memory
    free(in->buffer);
    free(in);

    return 0;
}
