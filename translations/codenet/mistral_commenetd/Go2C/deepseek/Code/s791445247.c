#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a new Scanner type
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t pos;
} Scanner;

// Create a new Scanner instance
Scanner* newScanner(char *input, size_t input_size) {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->buffer = (char*)malloc(input_size);
    memcpy(s->buffer, input, input_size);
    s->buffer_size = input_size;
    s->pos = 0;
    return s;
}

// Parse an integer from the buffer
int scanInt(Scanner *s) {
    // Skip whitespace
    while (s->pos < s->buffer_size && (s->buffer[s->pos] == ' ' || s->buffer[s->pos] == '\n' || s->buffer[s->pos] == '\r' || s->buffer[s->pos] == '\t')) {
        s->pos++;
    }
    // Read the integer
    int result = 0;
    int sign = 1;
    if (s->pos < s->buffer_size) {
        if (s->buffer[s->pos] == '-') {
            sign = -1;
            s->pos++;
        }
        while (s->pos < s->buffer_size && s->buffer[s->pos] >= '0' && s->buffer[s->pos] <= '9') {
            result = result * 10 + (s->buffer[s->pos] - '0');
            s->pos++;
        }
    }
    return result * sign;
}

// Print a line with the given arguments
void Pln(int s, ...) {
    va_list args;
    va_start(args, s);
    for (int i = 0; i < s; i++) {
        int arg = va_arg(args, int);
        printf("%d\n", arg);
    }
    va_end(args);
}

int main() {
    // Read the first two integers from the standard input
    char input[] = "5 3"; // Example input
    Scanner *in = newScanner(input, sizeof(input) - 1);
    int n = scanInt(in);
    int k = scanInt(in);

    // Check if n is divisible by k
    if (n % k == 0) {
        // If it is, print 0
        Pln(1, 0);
    } else {
        // If not, print 1
        Pln(1, 1);
    }

    // Free the allocated memory
    free(in->buffer);
    free(in);

    return 0;
}
