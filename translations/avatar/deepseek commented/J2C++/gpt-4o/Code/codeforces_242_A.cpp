#include <iostream>
using namespace std;

int main() {
    int x, y, a, b;
    cin >> x; // Read first integer input
    cin >> y; // Read second integer input
    cin >> a; // Read third integer input
    cin >> b; // Read fourth integer input

    int count = 0; // Initialize counter to keep track of valid pairs

    // Nested loops to iterate through possible pairs (i, j)
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue; // Skip pairs where i is not greater than j
            count++; // Increment counter for each valid pair
        }
    }

    cout << count << endl; // Print the total count of valid pairs

    // Print each valid pair
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue; // Skip pairs where i is not greater than j
            cout << i << " " << j << endl; // Print each valid pair
        }
    }

    return 0; // End of the program
}

// <END-OF-CODE>
