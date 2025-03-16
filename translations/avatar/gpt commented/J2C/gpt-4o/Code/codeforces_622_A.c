#include <stdio.h>

#define BUFFERSIZE 512000

// Function to calculate the value at a given index based on a specific formula
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

// Method to solve the main problem
void solve() {
    long position;
    scanf("%ld", &position); // Read the position from input

    long nrstSeqStartIndx = 1; // Initialize the nearest sequence start index

    // Find the nearest sequence start index such that its value is less than the position
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Increment the nearest sequence start index until its value exceeds the position
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    // Get the starting index value for the nearest sequence
    long startIndex = getValueAtIndex(nrstSeqStartIndx);

    // Output the result, which is the difference between the position and the start index plus one
    printf("%ld\n", (position - startIndex) + 1);
}

// Main method to execute the program
int main() {
    solve(); // Call the solve method to process the input and produce output
    return 0; // Return success
}

// <END-OF-CODE>
