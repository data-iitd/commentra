#include <iostream>
using namespace std;

// Main function
int main() {
    int t; // Number of test cases
    cin >> t; // Read the number of test cases

    // Iterate through each test case
    for (int i = 0; i < t; i++) {
        int n; // Number of elements in the array
        cin >> n; // Read the number of elements

        // Print the maximum left sum
        cout << max(0, n - 2) << endl; // Calculate and print the maximum left sum
    }

    return 0; // Return success
}

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2 ? n - 2 : 0;
}

// Note: The maxLeft function is not used in the main function, 
// but it is included for completeness based on the original Java code.

