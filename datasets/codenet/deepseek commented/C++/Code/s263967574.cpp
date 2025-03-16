#include<iostream>
using namespace std;

int main() {
    // Include the iostream library for input and output operations
    int x;
    // Declare an integer variable 'x' to store the input value
    cin >> x;
    // Read an integer value from the standard input and store it in 'x'
    if (x >= 1200) 
        // Check if 'x' is greater than or equal to 1200
        cout << "ARC" << endl;
        // If the condition is true, print "ARC" to the standard output
    else 
        cout << "ABC" << endl;
        // Otherwise, print "ABC" to the standard output
    return 0;
    // Return 0 to indicate successful execution
}