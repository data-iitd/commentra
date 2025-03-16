#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Main {
public:
    // Method to solve the problem
    void solve() {
        // Read input values
        int x, t, a, b, da, db;
        cin >> x >> t >> a >> b >> da >> db;

        int first; // Position of first entity after i steps
        int second; // Position of second entity after j steps
        bool ok = false; // Flag to indicate if the target can be reached

        // Iterate through possible steps for the first entity
        for (int i = 0; i < t; i++) {
            first = a - (da * i); // Calculate position of first entity
            
            // Iterate through possible steps for the second entity
            for (int j = 0; j < t; j++) {
                second = b - (db * j); // Calculate position of second entity
                
                // Check if any of the conditions to reach target x are met
                if (second + first == x || second == x || first == x || x == 0) {
                    ok = true; // Set flag to true if target is reachable
                    break; // Exit inner loop if target is found
                }
            }
            if (ok) break; // Exit outer loop if target is found
        }

        // Output result based on whether the target can be reached
        if (ok)
            cout << "YES"; // Target can be reached
        else
            cout << "NO"; // Target cannot be reached
    }

    // Main method to run the program
    int main() {
        solve(); // Call the solve method to process the input
        return 0; // Return success
    }
};

// Entry point of the program
int main() {
    Main().main(); // Create an instance of Main and run it
    return 0; // Return success
}

// <END-OF-CODE>
