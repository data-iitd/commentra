#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to reverse a portion of the vector in place
void reva(vector<int>& b, int start, int end) {
    while (start < end) {
        swap(b[start], b[end]);
        start++;
        end--;
    }
}

int main() {
    // Read the number of elements in the array
    int n;
    cin >> n;
    vector<int> a(n); // Initialize a vector of integers with length n

    // Populate the vector with integers from input
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read each integer and store it in the vector
    }

    // Read the number of queries
    int q;
    cin >> q;
    // Process each query
    for (int i = 0; i < q; i++) {
        int b, e;
        cin >> b >> e; // Read the starting and ending indices for the reversal
        reva(a, b, e - 1); // Reverse the portion of the vector from index b to e-1
    }

    // Output the modified array
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " "; // Print a space before each element except the first
        }
        cout << a[i]; // Print the current element
    }
    cout << endl; // Print a newline after the output

    return 0;
}

// <END-OF-CODE>
