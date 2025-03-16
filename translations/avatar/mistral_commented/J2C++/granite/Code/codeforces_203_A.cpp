
#include <iostream> // Include the C++ I/O package
#include <string> // Include the C++ string package
#include <vector> // Include the C++ vector package
#include <algorithm> // Include the C++ algorithm package
#include <cmath> // Include the C++ math package
#include <cstdio> // Include the C++ standard input/output package
#include <cstdlib> // Include the C++ standard library package
#include <ctime> // Include the C++ standard time package
#include <climits> // Include the C++ standard limits package
#include <cctype> // Include the C++ standard character type package
#include <cstring> // Include the C++ standard string package
#include <cassert> // Include the C++ standard assert package
#include <iomanip> // Include the C++ standard input/output manipulators package

using namespace std; // Use the standard namespace

int main() { // Define the main function
    int x, t, a, b, da, db; // Declare variables x, t, a, b, da, and db
    cin >> x >> t >> a >> b >> da >> db; // Read the input values for x, t, a, b, da, and db
    bool ok = false; // Initialize ok to false
    for (int i = 0; i < t; i++) { // Run a loop to find the first value
        for (int j = 0; j < t; j++) { // Run a nested loop to find the second value
            if (a - (da * i) + b - (db * j) == x || a - (da * i) == x || b - (db * j) == x || x == 0) { // Check if the sum of the first and second values equals x or if either value equals x
                ok = true; // Set ok to true if a match is found
                break; // Exit the inner loop if a match is found
            }
        }
    }
    if (ok) { // Check if ok is true
        cout << "YES" << endl; // Print YES
    } else {
        cout << "NO" << endl; // Print NO
    }
    return 0; // Return 0 to indicate successful execution
}

