
#include <iostream> // Including the necessary header file for input/output
#include <vector> // Including the necessary header file for vectors
#include <algorithm> // Including the necessary header file for sorting

using namespace std; // Using the'std' namespace

int main() {
    int n; // Declaring the variable 'n' to store the size of the array
    cin >> n; // Reading the size of the array from input

    vector<int> a(n); // Declaring and initializing the vector 'a' of size 'n'
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Reading 'n' integers from input and storing them in the vector 'a'
    }

    vector<string> r; // Declaring a vector to store the operations
    int m = 0; // Initializing the index of the maximum absolute value element

    // Finding the index of the element with the maximum absolute value in the vector 'a'
    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }

    // Finding pairs of indices where one element is non-negative and the other is negative
    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) { // Using XOR to check if one is non-negative and the other is negative
            r.push_back(to_string(m + 1) + " " + to_string(i + 1)); // Adding the operation to the vector 'r'
        }
    }

    // Generating operations based on whether the maximum absolute value element is non-negative or negative
    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r.push_back(to_string(i + 1) + " " + to_string(i + 2)); // Adding the operation to the vector 'r'
        }
    } else {
        for (int i = n; i > 1; --i) {
            r.push_back(to_string(i) + " " + to_string(i - 1)); // Adding the operation to the vector 'r'
        }
    }

    // Sorting the vector 'r' in ascending order
    sort(r.begin(), r.end());

    // Printing the number of operations and the operations themselves
    cout << r.size() << endl;
    for (string s : r) {
        cout << s << endl; // Printing each operation in the vector 'r'
    }

    return 0; // Returning 0 to indicate successful execution
}

