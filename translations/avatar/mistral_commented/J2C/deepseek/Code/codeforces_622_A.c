#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512000

// Initialize constants
const int buffer_size = BUFFER_SIZE;

// Initialize scanner and print writer
static FILE *in = stdin;
static FILE *out = stdout;

// Main method
int main(int argc, char *argv[]) {
    init(); // Initialize input and output streams
    solve(); // Solve the problem
    closeIO(); // Close input and output streams
    return 0;
}

// Initialize input and output streams
void init() {
    // No need to initialize input stream in C
}

// Close input and output streams
void closeIO() {
    // No need to close input stream in C
    fclose(out); // Close output stream
}

// Solve the problem
void solve() {
    long position;
    scanf("%ld", &position); // Read the position from input
    solveHelper(position); // Solve the problem using helper method
}

// Helper method to solve the problem
void solveHelper(long position) {
    long nrstSeqStartIndx = 1; // Initialize index for the start of the next sequence

    // Binary search for the start index of the sequence containing the position
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2; // Multiply index by 2
    }

    // Linear search for the end index of the sequence containing the position
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++; // Increment index
    }

    // Print the answer
    long startIndex = getValueAtIndex(nrstSeqStartIndx); // Get the start index of the sequence
    fprintf(out, "%ld\n", (position - startIndex) + 1); // Print the length of the sequence
}

// Get the value at a given index
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2); // Calculate the value at the given index
}
