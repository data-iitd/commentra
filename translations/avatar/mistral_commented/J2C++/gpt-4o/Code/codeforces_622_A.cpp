#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Initialize constants
const int BUFFER_SIZE = 512000;

// Function to get the value at a given index
long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2); // Calculate the value at the given index
}

// Solve the problem
void solve() {
    long long position;
    cin >> position; // Read the position from input

    long long nrstSeqStartIndx = 1; // Initialize index for the start of the next sequence

    // Binary search for the start index of the sequence containing the position
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2; // Multiply index by 2
    }

    // Linear search for the end index of the sequence containing the position
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++; // Increment index
    }

    // Print the answer
    long long startIndex = getValueAtIndex(nrstSeqStartIndx); // Get the start index of the sequence
    cout << (position - startIndex) + 1 << endl; // Print the length of the sequence
}

// Main function
int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr); // Untie cin from cout for faster input

    solve(); // Solve the problem

    return 0; // Return success
}

// <END-OF-CODE>
