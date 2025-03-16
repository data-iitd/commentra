
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements in the list `w`
    int n;
    cin >> n;

    // Read the list of integers `w`
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // Initialize the variable `c` to 2
    int c = 2;

    // Loop through each element `i` in the list `w`
    for (int i : w) {
        // Check if `i` is equal to 1
        if (i == 1) {
            // Print the current value of `c`
            cout << c << endl;
        }
        // Check if `i` is even
        else if (i % 2 == 0) {
            // Toggle the value of `c` between 2 and 3-c (i.e., 1 or 3)
            c = 3 - c;
            // Print the new value of `c`
            cout << c << endl;
        }
        // If `i` is odd
        else {
            // Print the current value of `c`
            cout << c << endl;
        }
    }

    return 0;
}

