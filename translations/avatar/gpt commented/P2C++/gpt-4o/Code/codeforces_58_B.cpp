#include <iostream>
using namespace std;

int main() {
    // Read an integer input from the user
    int n;
    cin >> n;

    // Iterate from n down to 1
    for (int i = n; i > 0; i--) {
        // Check if i is a divisor of n
        if (n % i == 0) {
            // Update n to the current divisor i
            n = i;
            // Print the divisor followed by a space
            cout << i << " ";
        }
    }

    return 0;
}

// <END-OF-CODE>
