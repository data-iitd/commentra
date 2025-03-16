#include<iostream> // Include standard input/output library
#include<cmath>    // Include math library for mathematical functions

using namespace std; // Use standard namespace

int main() {
    int i, j, k, n; // Declare integer variables i, j, k, and n
    
    // Read an integer input from the user
    cin >> n;
    
    // Calculate and print the result based on the input n
    // The expression (24 + (24 - n)) simplifies to (48 - n)
    cout << 24 + (24 - n) << endl;
    
    return 0; // Return 0 to indicate successful execution
}

