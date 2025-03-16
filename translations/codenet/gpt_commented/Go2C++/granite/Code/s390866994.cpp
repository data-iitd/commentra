
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print output to the console
void out(int x) {
    cout << x << endl;
}

// Function to read an integer from input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a string from input
string getString() {
    string x;
    cin >> x;
    return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
    return a > b? a : b;
}

int min(int a, int b) {
    return a < b? a : b;
}

int asub(int a, int b) {
    return a > b? a - b : b - a;
}

int abs(int a) {
    return a >= 0? a : -a;
}

int main() {
    // Read the number of elements (N), maximum count (C), and time limit (K)
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> t(N); // Create a vector to hold the time values

    // Read N time values from input
    for (int i = 0; i < N; i++) {
        cin >> t[i]; // Store each time value in the vector
    }

    sort(t.begin(), t.end()); // Sort the time values in ascending order

    // Initialize variables for counting groups and tracking the end time
    int ans = 1; // Start with one group
    int cnt = 1; // Count of elements in the current group
    int end = t[0] + K; // Calculate the end time for the first group

    // Iterate through the sorted time values
    for (int i = 1; i < N; i++) {
        // Check if we can add the current time to the current group
        if (cnt < C && t[i] <= end) {
            cnt++; // Increment the count of the current group
        } else {
            // Start a new group since the current time exceeds the end time
            cnt = 1; // Reset the count for the new group
            end = t[i] + K; // Update the end time for the new group
            ans++; // Increment the group count
        }
    }
    out(ans); // Output the total number of groups formed
    return 0;
}

