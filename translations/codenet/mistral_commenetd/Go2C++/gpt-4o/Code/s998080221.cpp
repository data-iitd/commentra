// Include necessary headers
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

// Using standard namespace
using namespace std;

// Function to read an integer from input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Function to output the result
void out(int a) {
    cout << a << endl;
}

// Function to solve the problem
void solve() {
    // Read two integers N and K from input
    int N = nextInt();
    int K = nextInt();
    
    // Initialize a vector A of size N
    vector<int> A(N);
    
    // Read N integers from input and store them in the vector A
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
    }
    
    // Initialize variables maxProfit, maxCnt, and maxA
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];
    
    // Iterate through the vector A from the last index to the first index
    for (int i = N - 2; i >= 0; i--) {
        // Calculate the profit of the current transaction
        int profit = max(0, maxA - A[i]);
        
        // If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        
        // Update maxA with the maximum of the current element and maxA
        maxA = max(maxA, A[i]);
    }
    
    // Write the output to the console
    out(maxCnt);
}

// Main function
int main() {
    // Call the solve function to solve the problem
    solve();
    return 0;
}

// <END-OF-CODE>
