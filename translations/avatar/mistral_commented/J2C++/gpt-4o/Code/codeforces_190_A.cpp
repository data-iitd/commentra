// Importing necessary libraries for input/output and collections
#include <iostream>

using namespace std;

// Main function is the entry point of the C++ application
int main() {
    // Declaring a variable 'n' to read the first integer from standard input
    int n;
    cin >> n;

    // Declaring a variable 'm' to read the second integer from standard input
    int m;
    cin >> m;

    // Checking if 'n' is equal to zero
    if (n == 0) {
        // If 'm' is not equal to zero, print "Impossible"
        if (m != 0) {
            cout << "Impossible" << endl;
        } else { // If 'm' is also zero, print '0' space '0'
            cout << 0 << " " << 0 << endl;
        }
        // Returning from the main function
        return 0;
    }

    // Checking if 'm' is less than or equal to 'n'
    if (m <= n) {
        // If 'm' is zero, assign it the value 1
        if (m == 0) {
            m = 1;
        }
        // Printing 'n' and the sum of 'm' and 'n' minus one
        cout << n << " " << (m + n - 1) << endl;
        // Returning from the main function
        return 0;
    }

    // If 'm' is greater than 'n', print 'm' and the sum of 'm' and 'n' minus one
    cout << m << " " << (m + n - 1) << endl;

    return 0;
}

// <END-OF-CODE>
