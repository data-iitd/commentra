#include <iostream>
#include <algorithm> // Include the algorithm header for std::max and std::min

using namespace std;

int main() {
    long long x, y, a, b; // Use long long for larger integer values
    cin >> x >> y >> a >> b; // Read the input values
    
    long long j = 2, i, x1 = 0, y1 = 0, c = 0; // Initialize variables
    bool ans = true; // Initialize a boolean variable to track the result
    
    // Calculate the maximum of x and y and store it in c
    c = max(x, y);
    
    // If c is greater than b, print "0" and set ans to false
    if (c > b) {
        cout << "0" << endl;
        ans = false;
    }
    
    // Continue looping until c is divisible by the minimum of x and y or ans is false
    while (c % min(x, y) != 0 && ans) {
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
        long long count = 0;
        i = a;
        for (i = a; i <= b; i++) {
            if (i % c == 0) break; // Break if a multiple of c is found
        }
        if (i != b + 1) 
            cout << ((b - i) / c) + 1 << endl; // Print the number of multiples
        else 
            cout << "0" << endl;
    }
    
    return 0;
}
