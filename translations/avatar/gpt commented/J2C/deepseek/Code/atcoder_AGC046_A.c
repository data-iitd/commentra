#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastReader structure to read input efficiently
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastReader;

// Function to initialize the FastReader
FastReader* createFastReader() {
    FastReader *fr = (FastReader*)malloc(sizeof(FastReader));
    fr->buffer_size = 1024;
    fr->buffer = (char*)malloc(fr->buffer_size);
    fr->buffer_position = 0;
    return fr;
}

// Function to read the next token as a string
char* next(FastReader *fr) {
    // Skip any leading whitespace
    while (fr->buffer[fr->buffer_position] == ' ' || fr->buffer[fr->buffer_position] == '\n') {
        fr->buffer_position++;
    }
    
    // Find the end of the current token
    size_t start = fr->buffer_position;
    while (fr->buffer[fr->buffer_position] != ' ' && fr->buffer[fr->buffer_position] != '\n' && fr->buffer[fr->buffer_position] != '\0') {
        fr->buffer_position++;
    }
    
    // Allocate memory for the token and copy it
    char *token = (char*)malloc(fr->buffer_position - start + 1);
    strncpy(token, fr->buffer + start, fr->buffer_position - start);
    token[fr->buffer_position - start] = '\0';
    
    return token;
}

// Function to read the next token as an integer
int nextInt(FastReader *fr) {
    char *token = next(fr);
    int value = atoi(token);
    free(token);
    return value;
}

// Function to read the next token as a long
long nextLong(FastReader *fr) {
    char *token = next(fr);
    long value = atol(token);
    free(token);
    return value;
}

// Function to read the next token as a double
double nextDouble(FastReader *fr) {
    char *token = next(fr);
    double value = atof(token);
    free(token);
    return value;
}

// Function to read the next line as a string
char* nextLine(FastReader *fr) {
    // Skip any leading whitespace
    while (fr->buffer[fr->buffer_position] == ' ' || fr->buffer[fr->buffer_position] == '\n') {
        fr->buffer_position++;
    }
    
    // Find the end of the current line
    size_t start = fr->buffer_position;
    while (fr->buffer[fr->buffer_position] != '\n' && fr->buffer[fr->buffer_position] != '\0') {
        fr->buffer_position++;
    }
    
    // Allocate memory for the line and copy it
    char *line = (char*)malloc(fr->buffer_position - start + 1);
    strncpy(line, fr->buffer + start, fr->buffer_position - start);
    line[fr->buffer_position - start] = '\0';
    
    return line;
}

// Function to free the FastReader memory
void freeFastReader(FastReader *fr) {
    free(fr->buffer);
    free(fr);
}

// Main function to execute the program
int main() {
    // Create a FastReader object to read input efficiently
    FastReader *fr = createFastReader();
    
    // Read an integer input from the user
    int x = nextInt(fr);
    // Initialize a counter to keep track of the number of rotations
    int count = 0;
    // Store the original value of x for later use
    int tmp = x;
    // Reset x to 0 for the rotation calculation
    x = 0;
    
    // Loop until x completes a full rotation (360 degrees)
    while (x != 360) {
        // Increment x by the original input value
        x = x + tmp;
        // If x exceeds 360, wrap it around by subtracting 360
        if (x > 360) {
            x = x - 360;
        }
        // Increment the count of rotations
        count++;
    }
    
    // Output the total number of rotations needed to reach 360 degrees
    printf("%d\n", count);
    
    // Free the FastReader memory
    freeFastReader(fr);
    
    return 0;
}
