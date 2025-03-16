#include <iostream> // Include the iostream library for input and output
#include <sstream> // Include the sstream library for string stream
#include <string> // Include the string library
#include <vector> // Include the vector library
using namespace std; // Use the standard namespace

class Main {
public:
    void solve() { // Define a public method named solve
        int x, t, a, b, da, db; // Declare variables
        cin >> x >> t >> a >> b >> da >> db; // Read input values

        int first = 0; // Initialize first to zero
        int second = 0; // Initialize second to zero
        bool ok = false; // Initialize ok to false

        // Run a nested loop to find first and second
        for (int i = 0; i < t; i++) {
            first = a - (da * i); // Calculate first for the current i
            for (int j = 0; j < t; j++) {
                second = b - (db * j); // Calculate second for the current j

                // Check if second + first equals x or if either first or second equals x
                if (second + first == x || second == x || first == x || x == 0) {
                    ok = true; // Set ok to true if a match is found
                    break; // Exit the inner loop if a match is found
                }
            }
            if (ok) break; // Exit the outer loop if a match is found
        }

        // Print YES if ok is true, otherwise print NO
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    int main() { // Define the main method
        solve(); // Call the solve method
        return 0; // Return 0 to indicate successful execution
    }
};

int main() {
    Main().main(); // Create an instance of Main and call its main method
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
