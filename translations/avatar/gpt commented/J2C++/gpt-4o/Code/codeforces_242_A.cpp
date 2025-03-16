#include <iostream> // Include the iostream library for input and output
using namespace std;

int main() {
    // Declare variables to hold the input values
    int x, y, a, b;
    
    // Read four integers from the user
    cin >> x; // Upper limit for the first variable
    cin >> y; // Upper limit for the second variable
    cin >> a; // Lower limit for the first variable
    cin >> b; // Lower limit for the second variable
    
    // Initialize a counter to keep track of valid pairs
    int count = 0;
    
    // First nested loop to iterate through the range [a, x]
    for (int i = a; i <= x; i++) {
        // Second nested loop to iterate through the range [b, y]
        for (int j = b; j <= y; ++j) {
            // Skip the iteration if i is less than or equal to j
            if (i <= j) continue;
            
            // Increment the count for each valid pair (i, j)
            count++;
        }
    }
    
    // Output the total count of valid pairs
    cout << count << endl;
    
    // Second set of nested loops to print the valid pairs
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; ++j) {
            // Skip the iteration if i is less than or equal to j
            if (i <= j) continue;
            
            // Print the valid pair (i, j)
            cout << i << " " << j << endl;
        }
    }
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
