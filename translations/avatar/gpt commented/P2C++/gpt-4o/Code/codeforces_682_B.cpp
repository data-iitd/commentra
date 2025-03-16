#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a single integer
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers
vector<int> readIntList(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

int main() {
    // Read the number of elements
    int n = readInt(); // Number of elements in the list

    // Read the list of integers
    vector<int> l = readIntList(n); // List of integers from input

    // Initialize a variable to track unique counts
    int f = 1; // Starting count for unique elements
    sort(l.begin(), l.end()); // Sort the list to facilitate counting unique elements

    // Initialize a counter for unique elements
    int c = 0; // Counter for unique elements

    // Iterate through the sorted list to count unique elements
    for (int i : l) {
        if (i > c) { // Check if the current element is greater than the counter
            c++; // Increment the counter for unique elements
        }
    }

    // Output the total count of unique elements
    cout << c + 1 << endl; // Print the count of unique elements (including the first element)

    return 0;
}

// <END-OF-CODE>
