#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom Scanner type to read input efficiently
typedef struct {
    char *buffer;
    size_t bufferSize;
    size_t position;
} Scanner;

// Create a new Scanner instance with a specified buffer size
Scanner* NewScanner(size_t max) {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->buffer = (char*)malloc(max);
    s->bufferSize = max;
    s->position = 0;
    return s;
}

// Read and return an integer from the input
int Scanner_Int(Scanner *s) {
    size_t i = s->position;
    while (i < s->bufferSize && s->buffer[i] != ' ' && s->buffer[i] != '\n') {
        i++;
    }
    int result = atoi(&s->buffer[s->position]);
    s->position = i + 1;
    return result;
}

// Helper function to check if a character is a space character
int isSpace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

// Helper function to print a line of output
void Pln(int s) {
    printf("%d\n", s);
}

int main() {
    // Initialize a global Scanner instance to read from standard input
    Scanner *in = NewScanner(1048576);

    // Read two integers, n and k, from standard input
    int n = Scanner_Int(in);
    int k = Scanner_Int(in);

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        Pln(0);
    } else {
        // If n is not divisible by k, print 1
        Pln(1);
    }

    // Free allocated memory
    free(in->buffer);
    free(in);

    return 0;
}
