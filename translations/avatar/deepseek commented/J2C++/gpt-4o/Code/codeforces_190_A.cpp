#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the first and second integer input

    // Check if n is 0
    if (n == 0) {
        if (m != 0) // If n is 0 but m is not 0, print "Impossible"
            cout << "Impossible" << endl;
        else // If both n and m are 0, print "0 0"
            cout << 0 << " " << 0 << endl;
        return 0; // Exit the program
    }

    // If n is not 0, check if m is less than or equal to n
    if (m <= n) {
        if (m == 0) { // If m is 0, set m to 1
            m = 1;
        }
        cout << n << " " << (m + n - 1) << endl; // Print the values of n and m + n - 1
        return 0; // Exit the program
    }

    // If m is greater than n, print the values of m and m + n - 1
    cout << m << " " << (m + n - 1) << endl;

    return 0; // Exit the program
}

// <END-OF-CODE>
