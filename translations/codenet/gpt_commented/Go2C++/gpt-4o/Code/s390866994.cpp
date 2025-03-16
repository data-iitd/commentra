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
    int i;
    cin >> i; // Read the next integer
    return i; // Return the integer
}

int main() {
    // Read the number of elements (N), maximum count (C), and time limit (K)
    int N = getInt(), C = getInt(), K = getInt();
    vector<int> t(N); // Create a vector to hold the time values

    // Read N time values from input
    for (int i = 0; i < N; i++) {
        t[i] = getInt(); // Store each time value in the vector
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
}

// <END-OF-CODE>
