#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read integers from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a < b) ? b : a;
}

int main() {
    // Reads three integers H, W, and N from the standard input.
    int H = readInt();
    int W = readInt();
    int N = readInt();
    
    // Determines the maximum of H and W and assigns it to A.
    int A = max(H, W);
    
    // Calculates the result by dividing N by A and rounding up.
    // This is done by adding N-1 to the division result and then performing integer division by A.
    cout << (N + A - 1) / A << endl;

    return 0;
}

// <END-OF-CODE>
