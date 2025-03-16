#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent an arm with left and right bounds
struct Arm {
    int l, r;
};

// Function to read an integer from input
int scanInt() {
    int x;
    cin >> x; // Read the integer from standard input
    return x; // Return the integer value
}

// Main function where the program execution begins
int main() {
    // Read the number of arms
    int n = scanInt();
    
    // Create a vector to hold the arms
    vector<Arm> arms(n);
    
    // Read the arm data from input
    for (int i = 0; i < n; i++) {
        int x = scanInt(), l = scanInt(); // Read the center and length of the arm
        arms[i].l = x - l; // Calculate the left bound
        arms[i].r = x + l; // Calculate the right bound
    }
    
    // Sort the arms based on their right bounds
    sort(arms.begin(), arms.end(), [](const Arm &a, const Arm &b) {
        return a.r < b.r;
    });

    // Initialize the count of non-overlapping arms and the rightmost bound
    int ans = 1; // Start with the first arm
    int r = arms[0].r; // Set the rightmost bound to the right of the first arm
    
    // Iterate through the sorted arms to count non-overlapping arms
    for (int i = 1; i < n; i++) {
        // If the left bound of the current arm is greater than or equal to the rightmost bound
        if (arms[i].l >= r) {
            ans++; // Increment the count of non-overlapping arms
            r = arms[i].r; // Update the rightmost bound to the current arm's right bound
        }
    }
    
    // Print the total count of non-overlapping arms
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
