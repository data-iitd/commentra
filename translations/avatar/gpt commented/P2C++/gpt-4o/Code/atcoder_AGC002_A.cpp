#include <iostream>
using namespace std;

// Function to read an integer from standard input
int readInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Read two integers from input
    int a = readInt();
    int b = readInt();

    // Check if the first integer 'a' is positive
    if (a > 0) {
        cout << "Positive" << endl;  // Output 'Positive' if 'a' is greater than 0
    } else if (a <= 0 && b >= 0) {
        cout << "Zero" << endl;  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
    } else {
        // If 'a' is negative and 'b' is also negative
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;  // Output 'Negative' if the sum of 'a' and 'b' is even
        } else {
            cout << "Positive" << endl;  // Output 'Positive' if the sum of 'a' and 'b' is odd
        }
    }

    return 0;
}

// <END-OF-CODE>
