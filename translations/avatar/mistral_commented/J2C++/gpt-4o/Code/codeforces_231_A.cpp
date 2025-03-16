#include <iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

int main() { // Entry point of the program
    int t; // Declare a variable to hold the number of test cases
    cin >> t; // Read the number of test cases from standard input

    // Initialize a counter variable to keep track of the number of valid cases
    int count = 0;

    // Process each test case in a while loop
    while (t-- > 0) {
        int a, b, c; // Declare variables to hold the three integers
        cin >> a >> b >> c; // Read the three integers from standard input

        // Check if any of the given integers are equal to 1. If so, increment the counter.
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Increment the counter if any of the given integers are equal to 1
        }
    }

    // Print the value of the counter to the standard output
    cout << count << endl; // Output the count

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
