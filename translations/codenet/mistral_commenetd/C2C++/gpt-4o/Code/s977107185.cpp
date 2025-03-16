#include <iostream>
#include <vector>

using namespace std;

// Main function starts here
int main() {
    int N, // Declare variable N
        tmp, // Declare a temporary variable tmp
        count = 0; // Initialize counter variable count to 0

    // Read the number of elements in the array from user input
    cin >> N;

    // Declare a vector A to store the elements
    vector<int> A(N);

    // Read the elements of the array A from user input
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Read an element of the array A
    }

    // Perform bubble sort on the array A
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) { // Iterate through the array from last to first
            if (A[j] < A[j - 1]) { // Check if the current element is smaller than the previous one
                tmp = A[j]; // Swap the elements if they are in wrong order
                A[j] = A[j - 1];
                A[j - 1] = tmp;

                count++; // Increment the counter for each swap
            }
        }
    }

    // Print the sorted array A
    for (int i = 0; i < N; i++) {
        cout << A[i]; // Print an element of the array A
        if (i < N - 1) cout << " "; // Add a space between elements, except the last one
    }

    cout << endl; // Print a newline character after the sorted array

    // Print the number of swaps (count) made during sorting
    cout << count << endl;

    // Main function ends here with a return value of 0
    return 0;
}
// <END-OF-CODE>
