#include <iostream>
#include <vector>

using namespace std;

// Declare global variables
int n, r, p, c;

int main() {
    // Infinite loop to continuously accept input until a termination condition is met
    while (true) {
        // Read the values of n and r from the user
        cin >> n >> r;
        
        // Check for the termination condition (both n and r are zero)
        if (n == 0 && r == 0) break;
        
        // Initialize vector a with values from n down to 1
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = n - i; // Fill vector a with decreasing values starting from n
        }
        
        // Process r operations as specified by the user
        for (int i = 0; i < r; i++) {
            // Create a copy of the current state of vector a
            vector<int> b = a; // Save the current configuration of a into b
            
            // Read the values of p and c for the current operation
            cin >> p >> c;

            // Update the first c elements of vector a based on the values from vector b
            for (int j = 0; j < c; j++) {
                a[j] = b[p - 1 + j]; // Move elements from b to a based on p and c
            }
            
            // Shift the remaining elements in vector a
            for (int j = c; j < c + p - 1; j++) {
                a[j] = b[j - c]; // Continue filling a with the remaining elements from b
            }
        }
        
        // Output the first element of vector a after all operations
        cout << a[0] << endl;
    }
    
    return 0; // End of the program
}

// <END-OF-CODE>
