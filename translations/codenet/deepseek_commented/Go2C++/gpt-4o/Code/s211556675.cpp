#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return std::max(a, std::max(b, c));
}

int main() {
    // Read input values
    int A = readInt();
    int B = readInt();
    int C = readInt();
    int K = readInt();
    
    // Determine the maximum value among A, B, and C
    int ma = max(A, B, C);
    
    // Calculate the sum of the other two values
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }
    
    // Double the maximum value K times
    for (int i = 0; i < K; i++) {
        ma *= 2;
    }
    
    // Print the final result
    cout << ma + rest << endl;

    return 0;
}

// <END-OF-CODE>
