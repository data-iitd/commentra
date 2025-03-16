#include <iostream>
#include <cmath>

using namespace std;

const int BUFFERSIZE = 512000;

// Function to calculate the value at a specific index in the sequence.
long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2);
}

// Function to solve the problem.
void solve() {
    long long position;
    cin >> position;
    long long nrstSeqStartIndx = 1;

    // Find the starting index of the sequence where the position might be located.
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Find the exact position within the sequence.
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    long long startIndex = getValueAtIndex(nrstSeqStartIndx);
    cout << (position - startIndex) + 1 << endl;
}

// Main function to initialize the input and call the solve function.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// <END-OF-CODE>
