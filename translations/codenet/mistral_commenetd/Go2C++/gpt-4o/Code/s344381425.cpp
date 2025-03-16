// Import the iostream library for input and output
#include <iostream>

using namespace std;

int main() {
    // Declare and initialize three integer variables "a", "b", and "c"
    int a, b, c;
    
    // Read values from the standard input
    cin >> a >> b >> c;

    // Check if the condition "a < b && b < c" is true using an if statement
    if (a < b && b < c) {
        // If the condition is true, print "Yes" to the standard output
        cout << "Yes" << endl;
    } else {
        // If the condition is false, print "No" to the standard output
        cout << "No" << endl;
    }

    // Return from the main function
    return 0;
}

// <END-OF-CODE>
