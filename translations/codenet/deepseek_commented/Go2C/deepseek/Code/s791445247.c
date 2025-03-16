#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom Scanner type to read input efficiently.
typedef struct {
    char *buffer;
    size_t bufferSize;
    size_t position;
} Scanner;

// Create a new Scanner instance with the given buffer size.
Scanner* NewScanner(size_t max) {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->buffer = (char*)malloc(max);
    s->bufferSize = max;
    s->position = 0;
    return s;
}

// Read a line from the input and store it in the buffer.
void readLine(Scanner *s, FILE *stream) {
    size_t pos = 0;
    char ch;
    while ((ch = fgetc(stream)) != '\n' && ch != EOF) {
        if (pos < s->bufferSize - 1) {
            s->buffer[pos++] = ch;
        }
    }
    s->buffer[pos] = '\0';
    s->position = 0;
}

// Read and return an integer from the input.
int scanInt(Scanner *s) {
    int result = 0;
    int sign = 1;
    int ch = s->buffer[s->position++];
    while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
        ch = s->buffer[s->position++];
    }
    if (ch == '-') {
        sign = -1;
        ch = s->buffer[s->position++];
    }
    while (ch >= '0' && ch <= '9') {
        result = result * 10 + (ch - '0');
        ch = s->buffer[s->position++];
    }
    return result * sign;
}

// Helper function to print a line of output.
void Pln(int s, ...) {
    printf("%d\n", s);
}

int main() {
    // Initialize a global Scanner instance to read from standard input.
    Scanner *in = NewScanner(1048576);

    // Read two integers, n and k, from the input.
    int n = scanInt(in);
    int k = scanInt(in);

    // Check if n is divisible by k.
    if (n % k == 0) {
        // If n is divisible by k, print 0.
        Pln(0);
    } else {
        // If n is not divisible by k, print 1.
        Pln(1);
    }

    // Free the allocated memory for the Scanner.
    free(in->buffer);
    free(in);

    return 0;
}
