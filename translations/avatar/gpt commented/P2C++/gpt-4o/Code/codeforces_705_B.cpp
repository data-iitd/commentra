#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Use fast input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    // Initialize a variable 'c' to track the output state
    int c = 2;

    // Iterate through each element in the list 'w'
    for (int i : w) {
        // If the current element is 1, print the current value of 'c'
        if (i == 1) {
            cout << c << "\n";
        }
        // If the current element is even, toggle 'c' between 2 and 3
        else if (i % 2 == 0) {
            c = 3 - c;  // This will switch c between 2 and 3
            cout << c << "\n";
        }
        // If the current element is odd (and not 1), print the current value of 'c'
        else {
            cout << c << "\n";
        }
    }

    return 0;
}

// <END-OF-CODE>
