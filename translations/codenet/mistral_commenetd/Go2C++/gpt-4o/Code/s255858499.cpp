#include <iostream>
using namespace std;

int main() {
    // Declare variables to store the two integers
    int a, b;

    // Read the first two integers from stdin
    cin >> a >> b;

    // Check if the product of a and b is odd or even
    if (a * b % 2 != 0) {
        // If the product is odd, print "Odd" to stdout
        cout << "Odd" << endl;
    } else {
        // If the product is even, print "Even" to stdout
        cout << "Even" << endl;
    }

    return 0;
}

// <END-OF-CODE>
