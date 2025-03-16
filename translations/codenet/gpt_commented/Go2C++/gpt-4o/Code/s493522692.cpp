#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Utility functions for input and mathematical operations

// Function to read an integer from input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Function to calculate the minimum of two integers
int minInt(int a, int b) {
    return (a < b) ? a : b;
}

// Main function
int main() {
    // Read the number of 'S' and 'c'
    int N = nextInt();
    int M = nextInt();
    
    int tmp = minInt(N, M / 2); // Calculate the minimum of N and half of M
    int ans = 0;
    ans += tmp; // Add the temporary value to the answer
    N -= tmp; // Decrease N by the temporary value
    M -= tmp * 2; // Decrease M by twice the temporary value
    
    // Output the final answer, which includes the remaining M divided by 4
    cout << ans + M / 4 << endl;

    return 0;
}

// <END-OF-CODE>
