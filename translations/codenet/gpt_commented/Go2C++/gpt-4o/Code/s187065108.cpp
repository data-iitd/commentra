#include <iostream>
#include <vector>

using namespace std;

// Function to read an integer from input
int scanInt() {
    int num;
    cin >> num; // Read an integer from standard input
    return num; // Return the integer
}

// Main function is the entry point of the program
int main() {
    // Read three integers from input: r, D, and x
    int r = scanInt();
    int D = scanInt();
    int x = scanInt();
    
    // Perform calculations and print the result for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r * x - D; // Update x based on the formula
        cout << x << endl; // Print the current value of x
    }
    
    return 0; // Indicate successful completion
}

// <END-OF-CODE>
