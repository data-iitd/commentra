#include <bits/stdc++.h> // Import the C++ standard library
using namespace std; // Import the C++ standard library namespace

int main() { // Define a main function
    ios_base::sync_with_stdio(false); // Turn off synchronization between C++ standard input and output streams
    cin.tie(NULL); // Turn off synchronization between C++ standard input and output streams
    int x, t, a, b, da, db; // Declare variables x, t, a, b, da, and db
    cin >> x >> t >> a >> b >> da >> db; // Read the first six integers from the standard input
    bool ok = false; // Initialize a boolean variable named ok to false
    for (int i = 0; i < t; i++) { // Run a loop from 0 to t
        int first = a - (da * i); // Calculate first for the current i
        for (int j = 0; j < t; j++) { // Run a loop from 0 to t
            int second = b - (db * j); // Calculate second for the current j
            if (second + first == x || second == x || first == x || x == 0) { // Check if second + first equals x or if either first or second equals x
                ok = true; // Set ok to true if a match is found
                break; // Exit the inner loop if a match is found
            }
        }
    }
    if (ok) { // Check if ok is true
        cout << "YES"; // Print YES
    } else { // Otherwise
        cout << "NO"; // Print NO
    }
    return 0; // Return 0 from the main function
}

