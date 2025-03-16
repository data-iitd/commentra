#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

// Initialize constants
const int BUFFER_SIZE = 512000;

// Initialize input and output streams
static FILE* input_stream = stdin;
static FILE* output_stream = stdout;

// Main method
int main() {
    init(); // Initialize input and output streams
    solve(); // Solve the problem
    closeIO(); // Close input and output streams
    return 0;
}

// Initialize input and output streams
void init() {
    // Initialize input stream
    input_stream = fopen("input.txt", "r");
    if (input_stream == NULL) {
        cerr << "Error opening input file." << endl;
        exit(1);
    }
}

// Close input and output streams
void closeIO() {
    fclose(input_stream); // Close input stream
    fclose(output_stream); // Close output stream
}

// Solve the problem
void solve() {
    long long position;
    cin >> position; // Read the position from input
    solveHelper(position); // Solve the problem using helper method
}

// Helper method to solve the problem
void solveHelper(long long position) {
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

// Get the value at a given index
long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2); // Calculate the value at the given index
}

