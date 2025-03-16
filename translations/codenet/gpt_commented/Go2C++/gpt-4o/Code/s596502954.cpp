#include <iostream>
#include <vector>

using namespace std;

// Function to read an integer from standard input
int nextInt() {
    int i;
    cin >> i; // Read an integer
    return i; // Return the integer value
}

int main() {
    // Read two integers, sum them, and compare the result with a third integer
    if (nextInt() + nextInt() >= nextInt()) {
        cout << "Yes" << endl; // Print "Yes" if the sum is greater than or equal to the third integer
    } else {
        cout << "No" << endl; // Print "No" otherwise
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
