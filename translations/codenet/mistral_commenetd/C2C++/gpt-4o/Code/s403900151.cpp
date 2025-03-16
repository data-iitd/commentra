#include <iostream>
#include <vector>
using namespace std;

// The main function is the entry point of the program
int main() {
    int n, r, p, c; // Declare variables n, r, p, c of type int

    // An infinite loop until the user inputs 0 for both n and r
    while (true) {
        cin >> n >> r; // Read the values of n and r from the standard input
        if (n == 0 && r == 0) // Check if both n and r are 0
            break; // If yes, break out of the loop

        vector<int> a(n); // Declare vector a of size n
        for (int i = 0; i < n; i++)
            a[i] = i + 1; // Initialize vector a with values from 1 to n

        // Iterate r times
        for (int i = 0; i < r; i++) {
            cin >> p >> c; // Read the values of p and c from the standard input
            vector<int> b(c); // Declare vector b of size c

            // Initialize vector b with elements from vector a
            for (int j = 0; j < c; j++)
                b[j] = a[n - p - c + 1 + j];

            // Shift elements of vector a to the left by p-1 positions
            for (int j = 0; j < p - 1; j++)
                a[n - p + j + 1] = a[n - p + j];

            // Copy elements from vector b to the end of vector a
            for (int j = n - p - c + 1, k = 0; k < c; j++, k++) {
                a[j] = b[k];
            }

            // Print the last element of vector a
            cout << a[n - 1] << endl;
        }
    }
    return 0;
}

// <END-OF-CODE>
