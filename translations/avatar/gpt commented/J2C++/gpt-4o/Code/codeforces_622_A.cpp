#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

// Define a constant for the buffer size used in input and output operations
const int BUFFERSIZE = 512000;

// Function to calculate the value at a given index based on a specific formula
long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2);
}

// Method to solve the main problem
void solve() {
    // Read the position from input
    long long position;
    cin >> position;

    // Initialize the nearest sequence start index
    long long nrstSeqStartIndx = 1;

    // Find the nearest sequence start index such that its value is less than the position
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Increment the nearest sequence start index until its value exceeds the position
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    // Get the starting index value for the nearest sequence
    long long startIndex = getValueAtIndex(nrstSeqStartIndx);

    // Output the result, which is the difference between the position and the start index plus one
    cout << (position - startIndex) + 1 << endl;
}

// Main method to execute the program
int main() {
    // Call the solve method to process the input and produce output
    solve();

    return 0;
}

// <END-OF-CODE>
