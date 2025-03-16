#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n; // Declaring the size of the array
    cin >> n; // Reading the size of the array
    int a[n]; // Declaring and initializing the array 'a' of size 'n'
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Filling the array 'a' with 'n' integers from input
    }

    vector<string> r; // Declaring an ArrayList to store the operations
    int m = 0; // Initializing the index of the maximum absolute value element

    // Finding the index of the element with the maximum absolute value in the array 'a'
    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }

    // Finding pairs of indices where one element is non-negative and the other is negative
    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) { // Using XOR to check if one is non-negative and the other is negative
            r.push_back(to_string(m + 1) + " " + to_string(i + 1)); // Adding the operation to the ArrayList 'r'
        }
    }

    // Generating operations based on whether the maximum absolute value element is non-negative or negative
    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r.push_back(to_string(i + 1) + " " + to_string(i + 2)); // Adding the operation to the ArrayList 'r'
        }
    } else {
        for (int i = n; i > 1; --i) {
            r.push_back(to_string(i) + " " + to_string(i - 1)); // Adding the operation to the ArrayList 'r'
        }
    }

    // Printing the number of operations and the operations themselves
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }

    return 0;
}

