#include <stdio.h>
#include <stdlib.h>

// Initialize constants
#define BUFFER_SIZE 512000

// Function prototypes
long getValueAtIndex(long index);
void solveHelper(long position);
void solve();

// Main function
int main() {
    // Initialize input and output streams
    solve(); // Solve the problem
    return 0; // Exit the program
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
    printf("%ld\n", (position - startIndex) + 1); // Print the length of the sequence
}

// Get the value at a given index
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2); // Calculate the value at the given index
}
