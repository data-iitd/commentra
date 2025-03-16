#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512000

// Step 2: Define the FILE and Scanner for input and output operations.
FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

// Step 3: Implement the solve method to find the position of a given value in a sequence.
void solve() {
    long position;
    fscanf(in, "%ld", &position);
    long nrstSeqStartIndx = 1;

    // Step 4: Find the starting index of the sequence where the position might be located.
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Step 4: Find the exact position within the sequence.
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    fprintf(out, "%ld\n", (position - startIndex) + 1);
}

// Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

// Step 5: Implement the main method to initialize the input and call the solve method.
int main() {
    // Step 7: Initialize the input reader for the in class.
    init(stdin);
    solve();
    fclose(out);
    return 0;
}

// Step 7: Implement the in class to handle input operations.
void init(FILE *input) {
    // Assuming the input is already initialized in the main function
}
