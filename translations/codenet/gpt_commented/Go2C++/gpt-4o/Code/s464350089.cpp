#include <iostream>
#include <vector>

using namespace std;

// Define a constant for the modulo value
const int mod = 1000000007;

int main() {
    // Read the values of h and n from input
    int h, n;
    cin >> h >> n;
    int a = 0; // Initialize a variable to accumulate the sum of integers

    // Loop to read n integers and accumulate their sum
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += x;
    }

    // Check if the accumulated sum is less than h
    if (h > a) {
        // If h is greater than the sum, print "No"
        cout << "No" << endl;
    } else {
        // Otherwise, print "Yes"
        cout << "Yes" << endl;
    }

    return 0;
}

// <END-OF-CODE>
