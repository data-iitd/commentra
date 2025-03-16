#include <stdio.h>

#define BUFFERSIZE 512000

// Function to calculate the value at a specific index in the sequence.
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

// Function to solve the problem.
void solve() {
    long position;
    scanf("%ld", &position);
    long nrstSeqStartIndx = 1;

    // Find the starting index of the sequence where the position might be located.
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Find the exact position within the sequence.
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    printf("%ld\n", (position - startIndex) + 1);
}

// Main function to initialize the input and call the solve function.
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
