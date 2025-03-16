#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to read an integer from standard input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Function to output the result
void out(int a) {
    cout << a << endl;
}

// Main function to execute the program
int main() {
    int N = nextInt(); // Read number of elements
    nextInt(); // Ignore the second value
    vector<int> A(N); // Create a vector to hold the elements

    for (int i = 0; i < N; i++) {
        A[i] = nextInt(); // Read each element into the vector
    }

    int maxProfit = 0; // Initialize maximum profit
    int maxCnt = 0;    // Initialize count of maximum profit occurrences
    int maxA = A[N - 1]; // Start with the last element as the maximum

    for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the vector
        int profit = max(0, maxA - A[i]); // Calculate profit based on the current element
        if (maxProfit < profit) { // If we found a new maximum profit
            maxProfit = profit; // Update maximum profit
            maxCnt = 1; // Reset count to 1
        } else if (maxProfit == profit) { // If we found another occurrence of the maximum profit
            maxCnt++; // Increment the count
        }
        maxA = max(maxA, A[i]); // Update the maximum element seen so far
    }

    out(maxCnt); // Output the count of maximum profit occurrences
    return 0; // Return success
}

// <END-OF-CODE>
