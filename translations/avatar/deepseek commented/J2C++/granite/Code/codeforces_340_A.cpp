
#include <iostream> // Include the necessary header file for input/output operations

using namespace std; // Use the standard namespace for input/output operations

int main() {
    long x, y, a, b, j = 2, i, c = 0; // Declare and initialize variables
    bool ans = true; // Declare a boolean variable to track the result
    
    // Read the input values for x, y, a, and b
    cin >> x >> y >> a >> b;
    
    // Calculate the maximum of x and y and store it in c
    c = max(x, y);
    
    // If c is greater than b, print "0" and set ans to false
    if (c > b) {
        cout << "0" << endl;
        ans = false;
    }
    
    // Continue looping until c is divisible by the minimum of x and y or ans is false
    while (c % min(x, y)!= 0 && ans) {
        if (x > y) {
            c = x * j; // Update c to be x multiplied by j
        } else {
            c = y * j; // Update c to be y multiplied by j
        }
        j++; // Increment j
        
        // If the updated c is greater than b, print "0" and break out of the loop
        if (c > b) {
            cout << "0" << endl;
            ans = false;
            break;
        }
    }
    
    // If ans is still true, calculate the number of multiples of c between a and b
    if (ans) {
        long count = 0;
        i = a;
        for (i = a; i <= b; i++) {
            if (i % c == 0) break; // Break if a multiple of c is found
        }
        if (i!= b + 1) 
            cout << ((b - i) / c) + 1 << endl; // Print the number of multiples
        else 
            cout << "0" << endl;
    }
    
    return 0; // Return 0 to indicate successful execution
}

