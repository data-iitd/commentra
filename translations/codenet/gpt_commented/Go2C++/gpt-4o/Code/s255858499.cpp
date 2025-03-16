#include <iostream>
using namespace std;

int main() {
    // Declare variables to hold the input integers
    int a, b;

    // Read the first integer from input
    cin >> a;
    // Read the second integer from input
    cin >> b;

    // Check if the product of a and b is odd
    if (a * b % 2 != 0) {
        // If the product is odd, print "Odd"
        cout << "Odd" << endl;
    } else {
        // If the product is even, print "Even"
        cout << "Even" << endl;
    }

    return 0;
}

// <END-OF-CODE>
