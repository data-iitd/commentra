#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from stdin
int intScanner() {
    int n;
    cin >> n;
    return n;
}

// Initialize the modulus value
const int mod = 1000000007;

// Function to read input and process it
int main() {
    // Read the number of elements in the array
    int n = intScanner();

    // Initialize a vector to store the elements
    vector<int> as(n);

    // Read the elements of the array into the as vector
    for (int i = 0; i < n; i++) {
        as[i] = intScanner();
    }

    // Initialize an empty vector xs to store the unique elements
    vector<int> xs;
    xs.push_back(as[0]);

    // Iterate through the array and add unique elements to the xs vector
    for (int j = 1; j < n; j++) {
        // Binary search to find the index where the current element should be inserted in the xs vector
        auto idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();

        // If the current element is not already present in the xs vector, append it
        if (idx == xs.size()) {
            xs.push_back(as[j]);
        } else {
            // Otherwise, replace the element at the found index with the current element
            xs[idx] = as[j];
        }
    }

    // Print the length of the xs vector
    cout << xs.size() << endl;

    return 0;
}

// <END-OF-CODE>
