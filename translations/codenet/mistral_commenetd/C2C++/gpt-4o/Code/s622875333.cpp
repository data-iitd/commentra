#include <iostream>
#include <vector>

using namespace std;

// Variables declaration
int n, r, i, j, p, c;

int main() {
    // Infinite loop until user inputs 0 for both n and r
    while (true) {
        cout << "Enter the number of elements in array a: ";
        cin >> n;
        cout << "Enter the number of rotations: ";
        cin >> r;

        if (n == 0 && r == 0) { // Exit the loop if n and r are both 0
            break;
        }

        // Initialize array a with the given size
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            a[i] = n - i; // Set the initial values of array a
        }

        // Rotate the array r times
        for (i = 0; i < r; i++) {
            cout << "\nBefore rotation " << (i + 1) << ":\n";
            // Print the current state of array a before rotation
            for (j = 0; j < n; j++) {
                cout << a[j] << " ";
            }
            cout << "\n";

            // Create a copy of array a and store it in array b
            vector<int> b = a; // Copy each element of array a to array b

            // Read the number of elements to be rotated and the position from user
            cout << "Enter the number of elements to be rotated: ";
            cin >> c;
            cout << "Enter the position: ";
            cin >> p;

            // Rotate the array b by c positions to the left
            for (j = 0; j < c; j++) {
                b[j] = b[j + 1]; // Shift each element of array b one position to the left
            }

            // Rotate the first part of array a by c positions to the left
            for (j = 0; j < c; j++) {
                a[j] = b[p - 1 + j]; // Shift each element of the first part of array a by c positions to the left
            }

            // Rotate the second part of array a by (p-c) positions to the right
            for (j = c; j < n; j++) {
                a[j] = b[j - c]; // Shift each element of the second part of array a by (p-c) positions to the right
            }

            // Print the current state of array a after rotation
            cout << "\nAfter rotation " << (i + 1) << ":\n";
            for (j = 0; j < n; j++) {
                cout << a[j] << " ";
            }
            cout << "\n";
        }

        // Print the first element of the final array a
        cout << "\nThe first element of the final array is: " << a[0] << "\n";
    }

    return 0;
}

// <END-OF-CODE>
