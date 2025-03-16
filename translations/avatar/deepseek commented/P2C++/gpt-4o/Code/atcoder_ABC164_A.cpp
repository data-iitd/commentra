#include <iostream>
using namespace std;

int main() {
    // Read the values of S and W from a single line of input
    int S, W;
    cin >> S >> W;

    // Check if the value of W is greater than or equal to S
    // If true, print "unsafe"
    if (S <= W) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

    return 0;
}

// <END-OF-CODE>
